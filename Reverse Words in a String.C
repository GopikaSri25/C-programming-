void reverseString(char* start, char* end) {
  char temp;
  while (end > start) {
    temp = *end;
    *end = *start;
    *start = temp;
    start++;
    end--;
  }
}

void removeSpaces(char* str) {
  char* ptr = str;

  while (*ptr != '\0') {
    while (*ptr == ' ') {
      ++ptr;
    }

    while (*ptr != ' ' && *ptr != '\0') {
      *str = *ptr;
      ++str;
      ++ptr;
    }

    if (*ptr != '\0') {
      *str = ' ';
      ++str;
    }
  }

  if (*(str - 1) == ' ') {
    *(str - 1) = '\0';
  }
  else {
    *str = '\0';
  }
}


char * reverseWords(char * str){
  char* end = &str[strlen(str) - 1];
  reverseString(str, end);
  int length = strlen(str);

  // Hi I am Jenish
  // hsineJ ma I iH
  // Jenish am I Hi
  int startWord = 0;
  int endWord = 0;
  int i = 0;
  while (i < length) {
    while (i < length && str[i] == ' ') {
      i++;
    }

    startWord = i;

    while (i < length && str[i] != ' ') {
      i++;
    }
    endWord = i - 1;

    reverseString(&str[startWord], &str[endWord]);
  }
  removeSpaces(str);
  return str;
}
