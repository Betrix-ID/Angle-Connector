> ![git text](/Selecting/img/IFS.png)

<h1>    ⚡ Angle Connector - ANGLE Renderer Switch Utility</h1>

<hr/>

> [!NOTE]
> **Description:**
> - Script C++ ini dibuat untuk mengatur sistem rendering Android dengan memanfaatkan driver ANGLE, memungkinkan aplikasi yang tidak mendukung Vulkan dapat menjalankannya melalui translasi dari OpenGL ES.
<hr/>

> [!IMPORTANT]
> **Features:**
> 1. **Switch to Vulkan via ANGLE**: Memaksa sistem untuk menggunakan Vulkan meskipun aplikasi hanya mendukung OpenGL ES.
> 2. **Switch back to OpenGL ES**: Mengembalikan sistem rendering ke default OpenGL ES.
> 3. **Auto Cleanup**: Menghapus konfigurasi grafis lama agar tidak bentrok dengan pengaturan baru.
> 4. **Lightweight Script**: Eksekusi cepat, tidak membebani sistem.
> 5. **Direct Launch ANGLE App**: Menjalankan aplikasi ANGLE langsung dari CLI.
> - *Efek dapat berbeda tergantung kompatibilitas perangkat dan versi Android.*
<hr/>

> [!TIP]
> **Tips Before Use:**
> - Pastikan perangkat Android memiliki dukungan Vulkan.
> - Disarankan perangkat sudah dalam keadaan root untuk mengatur properti sistem.
> - Cek log penggunaan ANGLE dengan perintah: <code>logcat -d | grep ANGLE</code>
<hr/>

> [!WARNING]
> **License & Credit Notice:**
> - Jika Anda menggunakan ulang script ini dalam modul atau proyek lain, mohon mencantumkan **credit ke pembuat asli**.
> - Dilarang menyebarluaskan versi modifikasi tanpa mencantumkan sumber.
> - Penggunaan script tanpa pemahaman yang tepat dapat menyebabkan ketidakstabilan pada grafis sistem.
<hr/>

<h2>🚀 Usage</h2>

<pre><code>AngleConnector [OPTION]
</code></pre>

<table>
<thead>
<tr><th>Option</th><th>Description</th></tr>
</thead>
<tbody>
<tr><td><code>-d</code></td><td>Aktifkan ANGLE Vulkan Mode - paksa sistem menggunakan Vulkan via ANGLE.</td></tr>
<tr><td><code>-L</code></td><td>Aktifkan kembali mode OpenGLES - reset ke renderer default Android.</td></tr>
<tr><td><code>-R</code></td><td>Jalankan aplikasi ANGLE & reset semua pengaturan grafis sebelumnya.</td></tr>
<tr><td><code>-h</code>, <code>--help</code></td><td>Tampilkan panduan penggunaan script ini.</td></tr>
</tbody>
</table>

<hr/>

<h2>📚 Example Commands</h2>

<pre><code># Paksa sistem gunakan Vulkan rendering melalui ANGLE
AngleConnector -d

# Kembali ke mode OpenGLES default
AngleConnector -L

# Jalankan aplikasi Angle dan reset semua konfigurasi grafis
AngleConnector -R
</code></pre>

<hr/>

<h2>ℹ️ More Info</h2>

<ul>
<li><a href="https://chromium.googlesource.com/angle/angle" target="_blank">Project ANGLE Documentation</a></li>
<li><a href="https://developer.android.com/ndk/guides/graphics" target="_blank">Android Vulkan Graphics Guide</a></li>
<li><a href="https://forum.xda-developers.com" target="_blank">Community Support - XDA</a></li>
</ul>

<hr/>

<div align="center" style="font-family: Arial, sans-serif;">

  <h2>🙌 If you like my work</h2>
  <p>Follow me, support me, or just send a coffee!</p>

  <div style="margin: 20px 0;">
    <a href="https://www.instagram.com/pai_calll?igsh=OGZnYmZ5OGdiMG9r" target="_blank" style="text-decoration: none;">
      <img src="https://img.shields.io/badge/-Instagram-red?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram">
    </a>
    <a href="https://www.tiktok.com/@pai.call" target="_blank" style="text-decoration: none;">
      <img src="https://img.shields.io/badge/-TikTok-black?style=for-the-badge&logo=tiktok&logoColor=white" alt="TikTok">
    </a>
    <a href="https://saweria.co/Uniccc" target="_blank" style="text-decoration: none;">
      <img src="https://img.shields.io/badge/-Saweria-yellow?style=for-the-badge&logo=saweria&logoColor=white" alt="Saweria">
    </a>
    <a href="https://t.me/Yeye_PID" target="_blank" style="text-decoration: none;">
      <img src="https://img.shields.io/badge/-Telegram-blue?style=for-the-badge&logo=telegram&logoColor=white" alt="Telegram">
    </a>
  </div>

  <hr style="border: none; height: 1px; background: #ddd; margin: 40px 0;">

</div>
