#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// @TODO: I only need 1 display, should I make this static?
struct Display {
  int initialised;
  GLFWwindow *window;
  int width;
  int height;
  void (*render)(void);
};

int initDisplay(Display *display);

void showDisplay(Display *display);
