#include "main.h"



lv_obj_t * selectorScreen = lv_obj_create(NULL);
lv_obj_t * confirmScreen = lv_obj_create(NULL);


int page;

static lv_style_t backgroundStyle;
static lv_style_t background2Style;
static lv_style_t background3Style;

static lv_style_t buttonStyle;
static lv_style_t switchStyle;
static lv_style_t redSwitch;
static lv_style_t blueSwitch;
static lv_style_t knobSwitch;
static lv_style_t goldSwitch;


lv_obj_t * colorLED;
lv_obj_t * colorSwitch;
 lv_obj_t * colorLabel1;
 lv_obj_t * driverSwitch;
 lv_obj_t * driverlabel;
lv_obj_t * autonDropDown;
lv_obj_t * pageDropDown;

void init(){
    initStyles();
    lv_obj_add_style(lv_scr_act(), &backgroundStyle,0);
    createSelectionScreen();




}

void initStyles(){

lv_style_init(&backgroundStyle);
lv_style_set_bg_color(&backgroundStyle, lv_color_hex3(0x000));
lv_style_set_text_color(&backgroundStyle, lv_color_hex3(0xfff));
lv_style_set_border_width(&backgroundStyle, 0);




lv_style_init(&buttonStyle);
lv_style_set_radius(&buttonStyle, 10);
lv_style_set_border_width(&buttonStyle, 1);
lv_style_set_border_color(&buttonStyle, lv_color_hex(0xBFA960));
lv_style_set_text_color(&buttonStyle, lv_color_hex3(0xfff));
lv_style_set_bg_color(&buttonStyle,lv_color_hex3(0x000));




lv_style_init(&redSwitch);
lv_style_set_bg_color(&redSwitch, lv_color_hex3(0xF00));
lv_style_set_radius(&redSwitch,10);


lv_style_init(&blueSwitch);
lv_style_set_bg_color(&blueSwitch, lv_color_hex(0x0076C0));
lv_style_set_radius(&blueSwitch,10);


lv_style_init(&goldSwitch);
lv_style_set_bg_color(&goldSwitch, lv_color_hex(0xBFA960));
lv_style_set_radius(&goldSwitch,10);

lv_style_init(&knobSwitch);
lv_style_set_bg_color(&knobSwitch, lv_color_hex(0x000000));
lv_style_set_border_width(&knobSwitch, 0);










lv_style_init(&background2Style);
lv_style_set_bg_color(&background2Style, lv_color_hex3(0xFF0));
lv_style_set_text_color(&background2Style, lv_color_hex3(0xfff));


lv_style_init(&background3Style);
lv_style_set_bg_color(&background3Style, lv_color_hex3(0x00F));
lv_style_set_text_color(&background3Style, lv_color_hex3(0xfff));

}










static void colorSwitchEventHandler(lv_event_t * event){
if(lv_obj_has_state(colorSwitch,LV_STATE_CHECKED)){
    lv_led_set_color(colorLED,lv_color_hex(0x0076C0));
    lv_label_set_text(colorLabel1,"BLUE");
    lv_obj_align_to(colorLabel1,colorLED,LV_ALIGN_CENTER,-2,0);
    
}else if(!lv_obj_has_state(colorSwitch,LV_STATE_CHECKED)){
    lv_led_set_color(colorLED,lv_color_hex(0xFF0000));
    lv_label_set_text(colorLabel1,"RED");
    lv_obj_align_to(colorLabel1,colorLED,LV_ALIGN_CENTER,0,0);


}


}

static void driverSwitchEventHandler(lv_event_t * event){

    if(lv_obj_has_state(driverSwitch,LV_STATE_CHECKED)){
        lv_label_set_text(driverlabel, "Your Driver is Sadeeb");
        
    }else{
        lv_label_set_text(driverlabel, "Your Driver is AJ");

    }



}

static void confirmSwitchEventHandler(lv_event_t * event){


    if(lv_obj_has_state(driverSwitch,LV_STATE_CHECKED)){
        driver = false;
    }else if(!lv_obj_has_state(driverSwitch,LV_STATE_CHECKED)){
        driver = true;
    }

    if(lv_obj_has_state(colorSwitch,LV_STATE_CHECKED)){
        isRed = false;
    }else if(!lv_obj_has_state(driverSwitch,LV_STATE_CHECKED)){
        isRed = true;
    }

    if(lv_dropdown_get_selected(autonDropDown) == 0){
        auton = true;
    }else if(lv_dropdown_get_selected(autonDropDown) == 1){
        auton = false;
    }else if(lv_dropdown_get_selected(autonDropDown) == 2){
        auton = NULL;
        skills = true;
    }

    if(lv_dropdown_get_selected(pageDropDown) == 0){
        lv_obj_clean(selectorScreen);
        lv_obj_t * nameObject = lv_img_create(lv_scr_act());
        //lv_img_set_src(nameObject, &l);
       // lv_obj_set_align(nameObject, LV_ALIGN_CENTER);
        //lv_obj_set_pos(nameObject, -10,-20);
        ready=true;
    }else if(lv_dropdown_get_selected(pageDropDown) == 1){
        ready=true;
    }else if(lv_dropdown_get_selected(pageDropDown) == 2){
       ready=true;
    }




}


void createSelectionScreen(){

    selectorScreen = lv_scr_act();

   lv_obj_add_style(selectorScreen,&backgroundStyle,0);

    lv_obj_t * colorSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(colorSection,&backgroundStyle,0);
    lv_obj_align(colorSection,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_set_size(colorSection,240,120);

    
    
    colorSwitch = lv_switch_create(colorSection);
    lv_obj_align_to(colorSwitch,colorSection,LV_ALIGN_BOTTOM_MID,-8,0);
    lv_obj_add_style(colorSwitch,&redSwitch, LV_PART_MAIN);
    lv_obj_add_style(colorSwitch,&blueSwitch, LV_PART_INDICATOR);
    lv_obj_add_style(colorSwitch,&knobSwitch, LV_PART_KNOB);
    lv_obj_set_width(colorSwitch,60);
    lv_obj_add_event_cb(colorSwitch,colorSwitchEventHandler,LV_EVENT_VALUE_CHANGED,NULL);
    

    lv_obj_t * colorLabel = lv_label_create(colorSection);
    lv_label_set_text(colorLabel, "Choose A Color");
    lv_obj_align_to(colorLabel,colorSection,LV_ALIGN_CENTER,0,-40);



    colorLED = lv_led_create(colorSection);
    lv_obj_align_to(colorLED,colorSection,LV_ALIGN_CENTER,-20,-7);
    lv_led_set_color(colorLED,lv_color_hex(0xFF0000));
    lv_obj_set_style_radius(colorLED,10,NULL);
    lv_obj_set_size(colorLED,60,30);

    colorLabel1 = lv_label_create(colorSection);
    lv_label_set_text(colorLabel1, "RED");
    lv_obj_align_to(colorLabel1,colorLED,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_text_color(colorLabel1, lv_color_hex(0x2B1B1B),NULL);







    
    




    lv_obj_t * autonSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(autonSection,&backgroundStyle,0);
    lv_obj_align(autonSection,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_size(autonSection,240,120);

    autonDropDown = lv_dropdown_create(autonSection);
    lv_dropdown_set_options(autonDropDown, "Winpoint\n"
                            "Elims\n"
                            "Skills");


    lv_obj_align(autonDropDown, LV_ALIGN_BOTTOM_MID, 0,0);
    lv_obj_set_style_bg_color(autonDropDown,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_color(autonDropDown,lv_color_hex(0xBFA960), LV_PART_MAIN);
    lv_obj_set_style_border_width(autonDropDown,2, LV_PART_MAIN);

    lv_obj_t * list = lv_dropdown_get_list(autonDropDown);
    lv_obj_set_style_bg_color(list,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_width(list,0, LV_PART_MAIN);

    lv_obj_set_style_bg_color(list,lv_color_hex3(0x000),  LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(list,lv_color_hex(0xBFA960),  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(list,2,  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_radius(list,10,  LV_PART_SELECTED | LV_STATE_CHECKED);


    
    lv_obj_t * autonLabel = lv_label_create(autonSection);
    lv_label_set_text(autonLabel, "Select An Auton");
    lv_obj_align_to(autonLabel,autonSection,LV_ALIGN_CENTER,0,-40);





    lv_obj_t * driverSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(driverSection,&backgroundStyle,0);
    lv_obj_align(driverSection,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_set_size(driverSection,240,120);

     
    driverlabel = lv_label_create(driverSection);
    lv_label_set_text(driverlabel, "Your Driver is AJ");
    lv_obj_align_to(driverlabel,driverSection,LV_ALIGN_TOP_MID,0,-15);

    driverSwitch = lv_switch_create(driverSection);
    lv_obj_center(driverSwitch);
    lv_obj_add_event_cb(driverSwitch, driverSwitchEventHandler, LV_EVENT_VALUE_CHANGED, driverlabel);
    lv_obj_add_style(driverSwitch,&goldSwitch, LV_PART_MAIN);
    lv_obj_add_style(driverSwitch,&goldSwitch, LV_PART_INDICATOR);
    lv_obj_add_style(driverSwitch,&knobSwitch, LV_PART_KNOB);
    lv_obj_set_width(driverSwitch,60);




lv_obj_t * pageSection = lv_obj_create(selectorScreen);
    lv_obj_add_style(pageSection,&backgroundStyle,0);
    lv_obj_align(pageSection,LV_ALIGN_BOTTOM_RIGHT,0,0);
    lv_obj_set_size(pageSection,240,120);

    pageDropDown = lv_dropdown_create(pageSection);
    lv_dropdown_set_options(pageDropDown, "Logo\n"
                            "Flag\n"
                            "Color");


    lv_obj_center(pageDropDown);
    lv_obj_set_style_bg_color(pageDropDown,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_color(pageDropDown,lv_color_hex(0xBFA960), LV_PART_MAIN);
    lv_obj_set_style_border_width(pageDropDown,2, LV_PART_MAIN);

    lv_obj_t * list1 = lv_dropdown_get_list(pageDropDown);
    lv_obj_set_style_bg_color(list1,lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_border_width(list1,0, LV_PART_MAIN);

    lv_obj_set_style_bg_color(list1,lv_color_hex3(0x000),  LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(list1,lv_color_hex(0xBFA960),  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(list1,2,  LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_set_style_radius(list1,10,  LV_PART_SELECTED | LV_STATE_CHECKED);


    
    lv_obj_t * pageLabel = lv_label_create(pageSection);
    lv_label_set_text(pageLabel, "Select An Ending Page");
    lv_obj_align_to(pageLabel,pageSection,LV_ALIGN_CENTER,0,-40);








    lv_obj_t * confirmButton = lv_btn_create(selectorScreen);
   lv_obj_add_style(confirmButton, &buttonStyle,0);
   lv_obj_t *confirmButtonLabel = lv_label_create(confirmButton);
   lv_label_set_text(confirmButtonLabel, "Confirm");
   lv_obj_set_align(confirmButtonLabel,LV_ALIGN_CENTER);
   lv_obj_set_size(confirmButton, 70,37);
   lv_obj_align_to(confirmButton,selectorScreen, LV_ALIGN_BOTTOM_MID,0,0); //Change Alignment
    lv_obj_add_event_cb(confirmButton,confirmSwitchEventHandler,LV_EVENT_CLICKED, NULL);






  

}