TARGET=sa0tour0
TITLE_ID=SKG5470UR
OBJS   = main.o font.o graphics.o

LIBS = -lSceCtrl_stub -lSceDisplay_stub -lScePower_stub -lSceVshBridge_stub

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -O3
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "sa0tour0" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
	-a pkg/Media/30=Media/30 \
	-a pkg/Media/10=Media/10 \
	-a pkg/Media/00=Media/00 \
	-a pkg/Media/20=Media/20 \
	-a pkg/Media/31=Media/31 \
	-a pkg/Media/11=Media/11 \
	-a pkg/Media/01=Media/01 \
	-a pkg/Media/21=Media/21 \$@


eboot.bin: $(TARGET).velf
	vita-make-fself -c $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo
