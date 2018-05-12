TOOLCHAIN_PATH=/home/girish/Projects/Alster/Argos-SBC-Source/Leica_Argos-N-BSP_Relv3.5/Leica_Argos-N-BSP_Relv3.5_source/LA.UM.5.5.r1-06100-8x96.0-N-Leica_ARGOS_Relv3.5/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin

OUT=/home/girish/Projects/Alster/Argos-SBC-Source/Leica_Argos-N-BSP_Relv3.5/Leica_Argos-N-BSP_Relv3.5_source/LA.UM.5.5.r1-06100-8x96.0-N-Leica_ARGOS_Relv3.5/out/target/product/msm8996

export PATH=$TOOLCHAIN_PATH:$PATH

#make KERNEL_SRC=/home/girish/Projects/Alster/Argos-SBC-Source/Leica_Argos-N-BSP_Relv3.5/Leica_Argos-N-BSP_Relv3.5_source/LA.UM.5.5.r1-06100-8x96.0-N-Leica_ARGOS_Relv3.5/out/target/product/msm8996/obj/kernel/msm-3.18/ ARCH=arm64 CROSS_COMPILE=aarch64-linux-android-

make KERNEL_SRC=$OUT/obj/kernel/msm-3.18/ ARCH=arm64 CROSS_COMPILE=aarch64-linux-android-
