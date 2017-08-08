struct FileLocation {
  const char * path;
  const char * fileName;
  const char * extension;
};

char * readFile(const char * uri);

char * readFileFl(FileLocation location);

char * createPath(FileLocation location);
