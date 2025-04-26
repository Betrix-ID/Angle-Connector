#include "Angle.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void shell(const char* message) {
    string cmd = "cmd notification post -S bigtext -t '♨️ Angle Connector ' 'Tag' '" + string(message) + "' > /dev/null 2>&1";
    system(cmd.c_str());
}

void clearAngleSettings() {
    system("for key in $(cmd settings list global | grep angle | cut -f1 -d=); do cmd settings delete global \"$key\"; done > /dev/null 2>&1");
    system("for key in $(cmd settings list global | grep driver | cut -f1 -d=); do cmd settings delete global \"$key\"; done > /dev/null 2>&1");
}

void setupAngleVulkan() {
    cout << "\nDescription:\n"
         << "  This function configures the Android device to use ANGLE with the Vulkan backend.\n"
         << "  It begins by clearing any existing ANGLE or graphics driver settings, then sets\n"
         << "  new global values to enable ANGLE and Vulkan rendering through 'skiavk'.\n"
         << "  Additional steps include granting necessary permissions to the ANGLE package,\n"
         << "  and optimizing the system by stopping user apps and clearing cache for better performance.\n"
         << "  Recommended for devices with stable Vulkan support seeking improved graphical performance.\n\n";
         
    clearAngleSettings();
    const char* cmds[] = {
        "cmd settings put global angle_gl_driver_all_angle 1",
        "cmd settings put global angle_debug_package org.chromium.angle",
        "setprop debug.angle.libs.suffix angle_in_apk",
        "pm grant com.android.angle android.permission.WRITE_SECURE_SETTINGS",
        "setprop debug.hwui.renderer skiavk",
        "setprop debug.hwui.use_vulkan 1",
        "sync"
    };

    for (const auto& cmd : cmds) system(cmd);

    FILE* fp = popen("pm list package -3 | cut -f2 -d:", "r");
    if (!fp) {
        perror("Failed to run command");
        return;
    }

    char package[256];
    while (fgets(package, sizeof(package), fp)) {
        package[strcspn(package, "\n")] = 0;

        if (strcmp(package, "me.piebridge.brevent") != 0 && strcmp(package, "com.samsung.android.app.smartcapture") != 0) {
            char command[512];
            snprintf(command, sizeof(command), "cmd activity force-stop --user 0 %s", package);
            system(command);
            snprintf(command, sizeof(command), "rm -rf /sdcard/Android/data/%s/cache", package);
            system(command);
            snprintf(command, sizeof(command), "cmd activity profile stop --user 0 %s", package);
            system(command);
            snprintf(command, sizeof(command), "cmd activity make-uid-idle --user 0 %s", package);
            system(command);
            printf("  \tCache cleared for %s\n", package);
        }
    }

    pclose(fp);
    shell("Successfully Applied custom Angle Vulkan");
}

void setupAngleOpenGLES() {
    cout << "\nDescription:\n"
         << "  This function sets up the Android device to utilize ANGLE with the OpenGL ES backend.\n"
         << "  It is ideal for devices that have compatibility issues or instability with Vulkan.\n"
         << "  The routine begins by purging previous driver settings, then applies OpenGL-specific props,\n"
         << "  such as forcing the use of GLES and setting ANGLE driver properties accordingly.\n"
         << "  As with the Vulkan setup, it also grants permissions and clears app cache to maximize efficiency.\n"
         << "  Useful for improving rendering on mid-range or older Android devices.\n\n";
   
    clearAngleSettings();
    const char* cmds[] = {
        "cmd settings put global angle_gl_driver_all_angle 1",
        "cmd settings put global angle_debug_package org.chromium.angle",
        "setprop debug.angle.libs.suffix angle_in_apk",
        "pm grant com.android.angle android.permission.WRITE_SECURE_SETTINGS",
        "setprop debug.hwui.renderer opengles",
        "setprop debug.hwui.force_opengles 1",
        "sync"
    };

    for (const auto& cmd : cmds) system(cmd);

    FILE* fp = popen("pm list package -3 | cut -f2 -d:", "r");
    if (!fp) {
        perror("Failed to run command");
        return;
    }

    char package[256];
    while (fgets(package, sizeof(package), fp)) {
        package[strcspn(package, "\n")] = 0;

        if (strcmp(package, "me.piebridge.brevent") != 0 && strcmp(package, "com.samsung.android.app.smartcapture") != 0) {
            char command[512];
            snprintf(command, sizeof(command), "cmd activity force-stop --user 0 %s", package);
            system(command);
            snprintf(command, sizeof(command), "rm -rf /sdcard/Android/data/%s/cache", package);
            system(command);
            snprintf(command, sizeof(command), "cmd activity profile stop --user 0 %s", package);
            system(command);
            snprintf(command, sizeof(command), "cmd activity make-uid-idle --user 0 %s", package);
            system(command);
            printf("  \tCache cleared for %s\n", package);
        }
    }

    pclose(fp);
    shell("Successfully Applied custom Angle OpenGLES");
}

void launchAngleApp() {
    cout << "\nDescription:\n"
         << "  This function attempts to launch the main activity of the ANGLE application manually.\n"
         << "  It also grants WRITE_SECURE_SETTINGS permission to the ANGLE package to ensure full\n"
         << "  system access is available for the renderer configurations.\n"
         << "  This is particularly useful for testing whether ANGLE is installed and operational,\n"
         << "  or for verifying changes after switching graphics backends.\n\n";

    system("cmd activity start -n com.android.angle/com.android.angle.MainActivity");
    system("pm grant com.android.angle android.permission.WRITE_SECURE_SETTINGS");
    shell("Successfully launched Angle application");
}