# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
# 这一句用来导出编译生成的so库
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/jniLibs/${ANDROID_ABI})
set(lib_name lame)
set(source_files

        bitstream.c
        encoder.c
        fft.c
        gain_analysis.c
        id3tag.c
        lame.c
        mpglib_interface.c
        newmdct.c
        presets.c
        psymodel.c
        quantize.c
        quantize_pvt.c
        reservoir.c
        set_get.c
        tables.c
        takehiro.c
        util.c
        vbrquantize.c
        VbrTag.c
        version.c

        )
#bitstream.c
#encoder.c
#fft.c
#gain_analysis.c
#id3tag.c
#lame.c
#mpglib_interface.c
#newmdct.c
#presets.c
add_library( # Sets the name of the library.
        ${lib_name}

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${source_files}
        )

add_library( # Sets the name of the library.
       lame-3100

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        lame_3.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        ${lib_name}
#        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

target_link_libraries( # Specifies the target library.
        lame-3100
        #        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})