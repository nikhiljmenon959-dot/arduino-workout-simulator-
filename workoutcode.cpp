#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define ch 2
#define count 3
#define option 4

String menu[]={"stats","add more work out"};
int menuitems=2;

String workout[]={"pushup","pullup","squat","situp","exit"};
int workoutitems=5;

int pushups=0;
int pullups=0;
int squats=0;
int situps=0;
int choice =1;
void workoutlog();
void menui(int choice);
void workoutip();
void add(int i);
void setup(){

pinMode(ch, INPUT_PULLUP);
pinMode(count, INPUT_PULLUP);
pinMode(option, INPUT_PULLUP);

if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
while (true); // OLED not found
}
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,10);
display.print("hello broter");
display.display();
delay(1000);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,10);
display.print("what would you like to do today");
display.display();
delay(1000);
display.clearDisplay();
}

void loop(){
    if (digitalRead(ch) == LOW){
        choice++;
        if(choice > menuitems){
            choice = 1;}
        menui(choice);

        delay(200);
    }

    if (digitalRead(option) == LOW){
        if (choice==1){display.clearDisplay();
          display.display();
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(0,10);
          display.print("your current workout log");
          display.display();
          delay(2000);
          display.clearDisplay();
          workoutlog();
        }
        if (choice==2){display.clearDisplay();
          display.display();
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(0,10);
          display.print("which would you like to add");
          display.display();
          delay(2000);
          display.clearDisplay();
          workoutip();
          display.display();
        }
    }
    else{
        menui(choice);
    }
}  
void workoutlog(){display.clearDisplay();
display.display();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,0);
display.print("pushup= ");
display.println(pushups);
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,10);
display.print("pullups= ");
display.println(pullups);
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,20);
display.print("squats= ");
display.println(squats);
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,30);
display.print("situps= ");
display.println(situps);
display.display();
delay(2000);
display.clearDisplay();
display.display();}
void menui(int choice){
  display.clearDisplay();
  for(int i = 0; i < menuitems; i++){
    display.setTextSize(1);
    display.setCursor(10, i * 20);
    if((i + 1) == choice){
      display.print("> ");
    }
    else{
      display.print("  ");
    }
    display.println(menu[i]);
  }
  display.display();
}
void workoutip(){
  int i=0;
  bool t=true;
  display.clearDisplay();
  while (t==true){
  display.clearDisplay();
  display.setTextSize(1);
  delay(150);
  if (digitalRead(ch)==LOW){
  i=i+1;}
  display.setCursor(10,20);
  if (i >= workoutitems){
    i = 0;
}
  display.println(workout[i]);
  delay(100);
  display.display();
  if (i==0){
    if(digitalRead(option)==LOW){
      t=false;
      int i=0;
      add(i);
      }}
  if (i==1){
    if(digitalRead(option)==LOW){
      t=false;
      int i=1;
      add(i);
      }}
  if (i==2){
    if(digitalRead(option)==LOW){
      t=false;
      int i=2;
      add(i);
      }}
  if (i==3){
    if(digitalRead(option)==LOW){
      t=false;
      int i=3;
      add(i);
      }}
  if (i==4){
    if(digitalRead(option)==LOW){
      t=false;
      }}
    }display.clearDisplay();
    delay(1000);
    display.display();
    menui(choice);
  }
void add(int i){
bool t=true;
while (t){
if (i==0){display.clearDisplay();
  display.setCursor(10,20);
  display.setTextSize(1);
  display.println(workout[i]);
  display.print("pushups= ");
  display.println(pushups);
  if (digitalRead(count)==LOW){
    pushups=pushups+1;
    delay(150);
  }display.display();
  delay(100);}
if (i==1){display.clearDisplay();
  display.setCursor(10,20);
  display.setTextSize(1);
  display.println(workout[i]);
  display.print("pullups= ");
  display.println(pullups);
  if (digitalRead(count)==LOW){
    pullups=pullups+1;
    delay(150);
  }display.display();
  delay(100);}
if (i==2){display.clearDisplay();
  display.setCursor(10,20);
  display.setTextSize(1);
  display.println(workout[i]);
  display.print("squats= ");
  display.println(squats);
  if (digitalRead(count)==LOW){
    squats=squats+1;
    delay(150);
  }display.display();
  delay(100);}
if (i==3){display.clearDisplay();
  display.setCursor(10,20);
  display.setTextSize(1);
  display.println(workout[i]);
  display.print("situps= ");
  display.println(situps);
  if (digitalRead(option)==LOW){
    t=false;
  }
  if (digitalRead(count)==LOW){
    situps=situps+1;
    delay(150);
  }display.display();
  delay(100);}
if (digitalRead(option)==LOW){
    t=false;}
}}


