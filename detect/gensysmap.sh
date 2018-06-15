cat /boot/System.map-`uname -r` | grep sys_call_table | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_open | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_read | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_close | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_getdents | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_kill | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep filldir | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
cat /boot/System.map-`uname -r` | grep sys_old_readdir | sed 's/^\([^ ]*\) \([^ ]*\) \([^ ]*\)$/#define sysmap_\3 0x\1/g' >> sysmap.h
