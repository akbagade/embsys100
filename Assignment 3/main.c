
int secondsToMicro(float sec)
{
  return sec * 1000000;
}

void changeLight(float time, unsigned int color)
{
    *((unsigned int*)0x40020014) = color;
   int counter =0;
   while (counter < secondsToMicro(time))
   {
     counter++;
   }
}

void off()
{
  changeLight(0.25f, 0x00);
}

void space()
{
  changeLight(1.0f, 0x00);
}

void dot()
{
  changeLight(0.5f, 0x20);
}

void dash()
{
  changeLight(.75f, 0x20);
}

void readMorse(char* text)
{
  for(int i =0; i < sizeof(text); i++)
  {
    if(*text == '.') {
      dot();
    }
    else if (*text == '-') {
      dash();
    }
    else if (*text == ' ') {
      space();
    }
    text++;
    if(*text != ' ') {
      off();
    }
  }
}

int main()
   {
     *((unsigned int*)0x40023830) =0x01;
     *((unsigned int*)0x40020000) =0xA8000400;
     char* morse = ".- -.- ... .... .- -.--";
     while(1)
     {
       readMorse(morse);
     }
     return 0;
   }