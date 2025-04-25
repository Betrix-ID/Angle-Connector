#include "Angle.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void shell(const char* message) {
    string cmd = "cmd notification post -S bigtext -t '♨️ Angle Connector ' 'Tag' '" + string(message) + "' > /dev/null 2>&1";
    system(cmd.c_str());
}

void clearAngleSettings() {
    cout << "\nDescription:\n"
         << "  [clearAngleSettings()]\n"
         << "  Menghapus semua pengaturan sistem terkait ANGLE dan driver grafis dari Global Settings.\n"
         << "  Ini adalah langkah awal sebelum menerapkan konfigurasi baru.\n";
         
    system("for key in $(cmd settings list global | grep angle | cut -f1 -d=); do cmd settings delete global \"$key\"; done > /dev/null 2>&1");
    system("for key in $(cmd settings list global | grep driver | cut -f1 -d=); do cmd settings delete global \"$key\"; done > /dev/null 2>&1");   
}

void setupAngleVulkan() {
    cout << "\nDescription:\n"
         << "  [setupAngleVulkan()]\n"
         << "  Mengatur sistem untuk menggunakan ANGLE backend Vulkan.\n"
         << "  Termasuk penghapusan setting lama, pemberian izin ke package, dan setprop renderer.\n"
         << "  Cocok untuk perangkat yang mendukung Vulkan untuk performa grafis lebih baik.\n";
         
    clearAngleSettings();
    const char* cmds[] = {
        "cmd settings put global angle_gl_driver_all_angle 1",
        "cmd settings put global angle_debug_package org.chromium.angle",
        "setprop debug.angle.libs.suffix angle_in_apk",
        "pm grant com.android.angle android.permission.WRITE_SECURE_SETTINGS",
        "setprop debug.hwui.renderer vulkan",
        "setprop debug.hwui.use_vulkan 1",
        "sync"
    };
    for (const auto& cmd : cmds) system(cmd);
    shell("Successfully Applay custem Angle Vulkan");
}

void setupAngleOpenGLES() {
    cout << "\nDescription:\n"
         << "  [setupAngleOpenGLES()]\n"
         << "  Mengatur sistem untuk menggunakan ANGLE backend OpenGL ES.\n"
         << "  Cocok untuk kompatibilitas lebih luas, terutama di perangkat yang tidak stabil dengan Vulkan.\n"
         << "  Proses ini juga memberi izin dan sinkronisasi sistem agar perubahan aktif.\n";
         
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
    shell("Successfully Applay custem Angle Opengles");
}

void launchAngleApp() {
    cout << "\nDescription:\n"
         << "  [launchAngleApp()]\n"
         << "  Mencoba menjalankan MainActivity dari aplikasi ANGLE.\n"
         << "  Memberikan izin WRITE_SECURE_SETTINGS ke aplikasi sebelum diluncurkan.\n"
         << "  Berguna untuk pengujian atau verifikasi apakah ANGLE terinstal dan aktif.\n";
         
    system("cmd activity start -n com.android.angle/com.android.angle.MainActivity");
    system("pm grant com.android.angle android.permission.WRITE_SECURE_SETTINGS");
    shell("Successfully Applay start application Angle....");
}