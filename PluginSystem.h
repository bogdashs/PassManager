//
// Created by Admin on 05.04.2026.
//

#ifndef PASSMANAGER_PLUGINSYSTEM_H
#define PASSMANAGER_PLUGINSYSTEM_H
#include <vector>

#include "PluginManager.h"
#include <windows.h>
#include <string>
#include <filesystem>
#include "utils.h"

class PluginSystem {
    private:
    std::pmr::vector<PluginManager*> plugins;
    std::vector<HMODULE> library;
    public:

    void loadPlugins(const std::string& folder_name) {
        namespace fs = std::filesystem;

        if (!fs::exists(folder_name)) {
            fs::create_directory(folder_name) ;
                return;

        }
        for (const auto& entry : fs::directory_iterator(folder_name)) {
            HMODULE hModule = LoadLibrary(entry.path().string().c_str());
            if (!hModule) continue;

            auto createFunc = (CreatePluginFunc)GetProcAddress(hModule, "CreatePlugin");

            if (!createFunc) {
                print("Failed to load plugin " + entry.path().string());
            }

            if (createFunc) {
                PluginManager* manager = createFunc();

                manager->onInit();

                plugins.push_back(manager);
                library.push_back(hModule);


            } else {
                FreeLibrary(hModule);
            }

        }
    }

    void showMenu() {
        for (auto& plugin : plugins) {
            plugin->onMenu();
        }
    }

    ~PluginSystem() {
        for (auto& plugin : plugins) delete plugin;
        for (auto& librarys : library) FreeLibrary(librarys);
    }

};


#endif //PASSMANAGER_PLUGINSYSTEM_H