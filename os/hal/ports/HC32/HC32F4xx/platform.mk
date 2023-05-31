# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS)/os/hal/ports/HC32/HC32F4xx/hc32_isr.c \
               $(CHIBIOS)/os/hal/ports/HC32/HC32F4xx/hal_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS)/os/hal/ports/HC32/HC32F4xx

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

else
endif

# Drivers compatible with the platform.
include $(CHIBIOS)/os/hal/ports/HC32/LLD/TIMv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/RCCv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/DMAv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/GPIOv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/SPIv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/USARTv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/I2Cv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/ADCv1/driver.mk
include $(CHIBIOS)/os/hal/ports/HC32/LLD/EXTIv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
