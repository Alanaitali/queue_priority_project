export CROSS="/opt/lafon/3.0/sysroots/x86_64-lafonsdk-linux/usr/bin/arm-lafon-linux-gnueabi"
export CXX="$CROSS/arm-lafon-linux-gnueabi-g++ -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a8 --sysroot=/opt/lafon/3.0/sysroots/armv7at2hf-neon-lafon-linux-gnueabi"

export LC_CTYPE=en_US.UTF-8
export LC_ALL=en_US.UTF-8


aclocal
autoconf
automake -a

./configure --prefix=${SDKTARGETSYSROOT}/usr ${CONFIGURE_FLAGS} \
	pcincludedir=/usr/include pclibdir=/usr/lib
