#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define LIGHT_FWD "DF"
#define LIGHT_LT "DL"
#define LIGHT_RT "DR"
#define LIGHT_REV "DB"
#define LIGHT_VLT "Dl"
#define LIGHT_VRT "Dr"

void setupDisplay();
void sendDisplayCommand(char *cmd);
void sendDisplayDirection(uint8_t direction, uint8_t active);
void sendDisplayBrightness(uint8_t brightness);

#endif
