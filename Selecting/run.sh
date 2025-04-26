#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 0 ] && [ "$(id -u)" -ne 2000 ]; then
	printf "[ Eror |@Yeye_nat(Yeye)]\n"
   exit 1
fi

# Cheking cpu.abi
     if [ ! -f /sdcard/Selecting/lib ]; then
	    architecture=$(getprop ro.product.cpu.abi)
	  if [ "$architecture" = "arm64-v8a" ]; then
		cp /sdcard/Selecting/lib/arm64 /sdcard/Selecting/zte
	elif [ "$architecture" = "armeabi-v7a" ]; then
		cp /sdcard/Selecting/lib/arm /sdcard/Selecting/zte
	fi
  fi
  
  # installing Aplikasi Angle
 if [ -f /sdcard/Selecting/Angle.apk ]; then
    if ! pm list packages | cut -f 2 -d : | grep -q com.android.angle; then
      	cp /sdcard/Selecting/Angle.apk /data/local/tmp
        pm install /data/local/tmp/Angle.apk > /dev/null 2>&1	
     fi
  else
    if pm list packages | cut -f 2 -d : | grep -q com.android.angle; then
		printf "\n"
	  fi
	fi
	
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ Angle Connector' 'Tag' "$sor" > /dev/null 2>&1
}
	
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Angle Connector...... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    :  [ Unifrom ] "
    echo "       - Release               :  25 - April - 2025"
    echo "       - Name Shell         :  Angle Connector"
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Angle Connector Custem. "
    sleep 2
     rm -rf /data/local/tmp/zte
     cp /sdcard/Selecting/zte /data/local/tmp 
     chmod +x /data/local/tmp/zte
     if [ "$1" = "-d" ]; then
          shell "Applying Angle for Vulkan profile. Please wait 1-4 seconds..."
          /data/local/tmp/zte -d
     elif [ "$1" = "-L" ]; then
          shell "Applying Angle for Opengles profile. Please wait 1-4 seconds..."
          /data/local/tmp/zte -L
     elif [ "$1" = "-S" ]; then
          shell "Applying start application profile. Please wait 1 seconds..."
          /data/local/tmp/zte -S
     elif [ "$1" = "-R" ]; then
           shell "Please wait 1-3 seconds Reset to Angle......"
           /data/local/tmp/zte -R
     elif [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
           /data/local/tmp/zte --help
        else
          printf "Failed to apply requested profile. Unknown option: %s\n" "$1"
         fi