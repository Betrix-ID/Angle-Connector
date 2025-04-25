#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstdio>
#include "Angle.h"
using namespace std;
#define SCRIPT_VERSION "1.0 [ Angle Custom Settings ]"

void Usage() {
    cout << "♨️ Angle Connector " << SCRIPT_VERSION << " - Automatic Device Optimization Utility\n\n"
         << "Usage:\n"
         << "  SpeedsterX [OPTION]\n\n"
         << "Options:\n"
         << "  -d           Apply ANGLE with Vulkan rendering (for supported devices).\n"
         << "  -L           Apply ANGLE with OpenGL ES rendering (for compatibility).\n"
         << "  -R           Reset all ANGLE settings and modifications.\n"
         << "  -S           Start/Launch the ANGLE application.\n"
         << "  -h, --help   Show this help message and exit.\n\n"
         << "Description:\n"
         <<  " Angle Connector is a lightweight C++ utility designed to enhance graphic compatibility\n" 
         << "  and rendering performance on Android devices. It automatically clears outdated graphic\n "
         << "  configurations, enables the ANGLE graphics driver (either Vulkan or OpenGL ES backend),\n"
         << "  and synchronizes system properties to apply changes effectively. By stopping background\n"
         << "  processes, clearing app cache, and adjusting the rendering pipeline, Angle Connector\n"
         << "  allows non-Vulkan-supported apps to run using Vulkan through ANGLE, improving both visual\n"
         << "  quality and system efficiency.\n\n"
         << "Examples:\n"
         << "  Apply Vulkan backend:\n"
         << "      SpeedsterX -d\n\n"
         << "  Apply OpenGL ES backend:\n"
         << "      SpeedsterX -L\n\n"
         << "  Launch ANGLE application:\n"
         << "      SpeedsterX -s\n\n"
         << "  Reset all modifications:\n"
         << "      SpeedsterX -R\n\n"
         << "Requirements:\n"
         << "  - Root access may be required.\n"
         << "  - Device must support 'adb shell' and required shell utilities.\n\n"
         << "More Info:\n"
         << "  ANGLE Overview              : https://chromium.googlesource.com/angle/angle\n"
         << "  Android Performance Docs    : https://developer.android.com/topic/performance\n"
         << "  Support Group                : https://t.me/speedsterx_support\n"
         << "  Community Discussions       : https://forum.xda-developers.com\n\n";
}

int main(int argc, char *argv[]) {
    /*
    Angle sebagai penghubung renderer di Android
    Contoh kasus:
    - Game seperti PUBG dan Genshin hanya mendukung OpenGL ES.
    - Device mendukung Vulkan, tapi game tidak bisa langsung pakai.

    Maka: 
    [Game] <--OpenGLES--> [ANGLE] <--Vulkan--> [Device]
    Dengan ANGLE, game yang tidak support Vulkan bisa tetap memakai Vulkan lewat bridging.
    Cek log: logcat -d | grep ANGLE
    */

    if (argc < 2) {
        Usage();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        string opt = argv[i];

        if (opt == "-d") {
            sleep(1);
            cout << "\n- Applying Vulkan backend via ANGLE...\n";
            setupAngleVulkan();
        } 
        else if (opt == "-L") {
            sleep(1);
            cout << "\n- Applying OpenGLES backend via ANGLE...\n";
            setupAngleOpenGLES();
        } 
        else if (opt == "-R") {
            sleep(1);
            cout << "\n- Resetting all ANGLE modifications...\n";
            clearAngleSettings();
            sleep(1);
            shell("success: Reset angle setings to default...");
        }
        else if (opt == "-S") {
            sleep(1);
            cout << "\n- Launching ANGLE application...\n";
            launchAngleApp();
        }
        else if (opt == "-h" || opt == "--help") {
            Usage();
        } 
        else {
            cout << "Error: Unknown option '" << opt << "'\n\n";
            Usage();
            return 1;
        }
    }

    sleep(1);
    cout << "\n"
         << "⚠️ This module is protected by copyright and\n"
         << "is intended for use by regular users only. Any\n"
         << "unauthorized modification, duplication, or\n"
         << "redistribution is strictly prohibited.\n"
         << "______________________________________________(+)\n\n";

    return 0;
}