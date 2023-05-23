# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/HC_EV_F4A0_LQ176_V10/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/HC_EV_F4A0_LQ176_V10

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
