```
sudo adb start-server

```

ret = execl("/system/bin/sh", "sh", "-c", "am start -a android.intent.action.MAIN -n   com.android.browser/.BrowserActivity", (char *)NULL);

Here's an example of Android.mk file that will build sourcetree containing assembly. To see a complete example check the hello-neon sample distributed in the NDK package.

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm  # remove this if you want thumb mode
LOCAL_ARM_NEON := true # remove this if you want armv5 mode

LOCAL_CFLAGS :=  -std=c99 -pedantic -v

LOCAL_SRC_FILES := # list your C, C++ and assembly sources here.
           # assembly source files ends with extension .S
           # add .arm after the extension if you want to compile in armv5 mode (default is thumb)
           # add .arm.neon to compile in armv7 mode

LOCAL_C_INCLUDES := $(LOCAL_PATH)

LOCAL_LDLIBS := -llog

LOCAL_MODULE := #the name of your shared library

include $(BUILD_SHARED_LIBRARY)
```
<application android:allowTaskReparenting=["true" | "false"]
             android:allowBackup=["true" | "false"]
             android:backupAgent="string"
             android:banner="drawable resource"
             android:debuggable=["true" | "false"]
             android:description="string resource"
             android:enabled=["true" | "false"]
             android:hasCode=["true" | "false"]
             android:hardwareAccelerated=["true" | "false"]
             android:icon="drawable resource"
             android:isGame=["true" | "false"]
             android:killAfterRestore=["true" | "false"]
             android:largeHeap=["true" | "false"]
             android:label="string resource"
             android:logo="drawable resource"
             android:manageSpaceActivity="string"
             android:name="string"
             android:permission="string"
             android:persistent=["true" | "false"]
             android:process="string"
             android:restoreAnyVersion=["true" | "false"]
             android:requiredAccountType="string"
             android:restrictedAccountType="string"
             android:supportsRtl=["true" | "false"]
             android:taskAffinity="string"
             android:testOnly=["true" | "false"]
             android:theme="resource or theme"
             android:uiOptions=["none" | "splitActionBarWhenNarrow"]
             android:usesCleartextTraffic=["true" | "false"]
             android:vmSafeMode=["true" | "false"] >
    . . .
</application>
```
