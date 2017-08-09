struct Texture {
  unsigned int id;
  int width;
  int height;
  int channelCount;
};

Texture createTexture(const char * fileName);
