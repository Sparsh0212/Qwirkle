#ifndef COLORS_H
#define COLORS_H

static void setTextColor(int code);
static void resetTextColor(int code);

enum Colors {
    RESET_COLOR,
    BLACK_TXT = 30,
    RED_TXT,
    GREEN_TXT,
    YELLOW_TXT,
    BLUE_TXT,
    MAGENTA_TXT,
    CYAN_TXT,
    WHITE_TXT,

       
};

static void setTextColor(int code){
     printf("\x1b[%dm", code);
}
static void resetTextColor(int code){
     printf("\x1b[%dm", RESET_COLOR);
}

#endif //COLORS_H
