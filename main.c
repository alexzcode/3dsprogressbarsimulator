#include <3ds.h>
#include <stdio.h>
int progress = 0;
int main(int argc, char **argv)
{
	printf("\x1b[2;12Hprogres bar simulator!!1!\r");
	printf("\x1b[3;12Hpress a to increas amount\r");
		while (aptMainLoop())
		{
			// input stuff
			hidScanInput();
			u32 kDown = hidKeysDown();
			consoleInit(GFX_TOP, NULL);
			while ((progress = 10)) printf("\x1b[5;6H[#---------]");
			while ((progress = 20)) printf("\x1b[5;6H[##--------]");
			while ((progress = 30)) printf("\x1b[5;6H[###-------]");
			while ((progress = 40)) printf("\x1b[5;6H[####------]");
			while ((progress = 50)) printf("\x1b[5;6H[#####-----]");
			while ((progress = 60)) printf("\x1b[5;6H[######----]");
			while ((progress = 70)) printf("\x1b[5;6H[#######---]");
			while ((progress = 80)) printf("\x1b[5;6H[########--]");
			while ((progress = 90)) printf("\x1b[5;6H[#########-]");
			while ((progress = 100)) printf("\x1b[5;6H[##########]");
			if (kDown & KEY_A) progress = progress + 1;
			if (kDown & KEY_START) if ((progress = 100)) break;
			consoleInit(GFX_BOTTOM, NULL);
			if ((progress = 100)) printf("\x1b[7;14Hcongradulations you won!1!!");
			if ((progress = 100)) printf("\x1b[8;14Hpress start to exit da gaem");
			gfxFlushBuffers();
			gfxSwapBuffers();
			gspWaitForVBlank();
		}
}
