//
// Created by Admin on 05.04.2026.
//

#ifndef PASSMANAGER_PLUGINMANAGER_H
#define PASSMANAGER_PLUGINMANAGER_H


class PluginManager {
public:
    virtual void onInit() = 0;
    virtual void onMenu() = 0;
    virtual void onUpdate() = 0;
};


typedef PluginManager* (__cdecl *CreatePluginFunc)();

#endif //PASSMANAGER_PLUGINMANAGER_H