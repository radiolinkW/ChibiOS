ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SDC TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1/hal_sdc_lld.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1/test/test.c
endif
else
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1/hal_sdc_lld.c
#PLATFORMSRC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1/test/test.c
endif

PLATFORMINC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1
#PLATFORMINC += $(CHIBIOS)/os/hal/ports/HC32/LLD/SDIOv1/test
