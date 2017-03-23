#include <stdio.h>

char FirstNotRepeatingChar(const char *pString)
{
  if(pString == NULL)
    return '\0';
  const int tableSize=256;
  unsigned int hashTable[tableSize];
  for(unsigned int i=0; i<tableSize; i++) {
    hashTable[i] = 0;
  }

  const char *pHashKey = pString;
  while(*(pHashKey) != '\0') {
    hashTable[*(pHashKey++)] ++;
  }

  pHashKey = pString;
  while(*pHashKey != '\0') {
    if (hashTable[*pHashKey] == 1)
      return *pHashKey;
  }

  return '\0';
}

int main()
{
  const char* p = "Hello, World";
  char c = FirstNotRepeatingChar(p);

  printf("%c\n", c);

  return 0;
}
