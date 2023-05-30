ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_USB TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/hal_usb_lld.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/test/test.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/test/usbcfg.c
endif
else
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/hal_usb_lld.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/test/test.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/test/usbcfg.c
endif

PLATFORMINC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1
#PLATFORMINC += $(CHIBIOS)/os/hal/ports/HC32/LLD/OTGv1/test
