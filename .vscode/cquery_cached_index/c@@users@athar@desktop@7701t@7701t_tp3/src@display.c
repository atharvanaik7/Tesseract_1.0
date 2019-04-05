#include "main.h"
#include "auton.h"

int x = 69;
int y = 80;

LV_IMG_DECLARE(drow);

LV_IMG_DECLARE(namelogo2);

LV_IMG_DECLARE(simpletext);

int color = 0;

// Uses the Little_vgl library for the touchscreen graphics
// Most of it doesn't work as intended so I commented it out

lv_obj_t *auton_label;


//////////////////////////// BUTTON FUNCTIONS ///////////////////////////////////////////////////////////////

static lv_res_t btn1_auton(lv_obj_t * btn) { backRed_autons(); return LV_RES_OK; }

static lv_res_t btn2_auton(lv_obj_t * btn) { frontRed_autons(); return LV_RES_OK; }

static lv_res_t btn3_auton(lv_obj_t * btn) { frontBlue_autons(); return LV_RES_OK; }

static lv_res_t btn4_auton(lv_obj_t * btn) { back_blue_autons(); return LV_RES_OK; }

// SKILLS BUTTON
static lv_res_t btn5_auton(lv_obj_t * btn) { auton_select = 5; return LV_RES_OK; }
// BACKBLUE FAR FLAGS BUTTON
static lv_res_t btn6_auton(lv_obj_t * btn) { auton_select = 4;  return LV_RES_OK; }
// CLOSE RED 9
static lv_res_t btn9_auton(lv_obj_t * btn) { auton_select = 1; return LV_RES_OK; }
// CLOSE BLUE 9
static lv_res_t btn11_auton(lv_obj_t * btn) { auton_select = 2; return LV_RES_OK; }
// BACK RED FAR
static lv_res_t btn13_auton(lv_obj_t * btn) { auton_select = 3; return LV_RES_OK; }
// BACK BUTTON
static lv_res_t back_but(lv_obj_t * btn) { display(); return LV_RES_OK; }

///////////////////////////////////////////////////// DISPLAY CODE /////////////////////////////////////////////

void display() {

  static lv_style_t background_style;
  lv_style_copy(&background_style, &lv_style_plain);
  background_style.body.main_color = LV_COLOR_BLACK;
  background_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *scr = lv_obj_create(NULL, NULL);
  lv_obj_set_style(scr, &background_style);
    lv_scr_load(scr);

  // Styles/////////////////////////////////////////////////////////////////////

  static lv_style_t button_style;
  lv_style_copy(&button_style, &lv_style_plain);
  button_style.body.main_color = LV_COLOR_GREEN;
  button_style.body.grad_color = LV_COLOR_GREEN;
  button_style.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled;
  lv_style_copy(&button_toggled, &lv_style_plain);
  button_toggled.body.main_color = LV_COLOR_RED;
  button_toggled.body.grad_color = LV_COLOR_RED;
  button_toggled.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled2;
  lv_style_copy(&button_toggled2, &lv_style_plain);
  button_toggled2.body.main_color = LV_COLOR_BLUE;
  button_toggled2.body.grad_color = LV_COLOR_BLUE;
  button_toggled2.text.color = LV_COLOR_WHITE;

  static lv_style_t button_skills;
  lv_style_copy(&button_skills, &lv_style_plain);
  button_skills.body.main_color = LV_COLOR_RED;
  button_skills.body.grad_color = LV_COLOR_BLUE;
  button_skills.text.color = LV_COLOR_WHITE;

  static lv_style_t title_style;
  lv_style_copy(&title_style, &lv_style_plain);
  title_style.text.font = &lv_font_dejavu_20;
  title_style.text.color = LV_COLOR_WHITE;

  static lv_style_t line_color;
  lv_style_copy(&line_color, &lv_style_plain);
  line_color.line.color = LV_COLOR_WHITE;


  // Text///////////////////////////////////////////////////////////////////////

  lv_obj_t *tesseract_title = lv_label_create(scr, NULL);
  lv_obj_set_style(tesseract_title, &title_style);
  lv_label_set_text(tesseract_title, "TESSERACT");
  lv_obj_align(tesseract_title, NULL, LV_ALIGN_IN_LEFT_MID, 50, 100);

  lv_obj_t *auton_title = lv_label_create(scr, NULL);
  lv_obj_set_style(auton_title, &title_style);
  lv_label_set_text(auton_title, "AUTONOMOUS");
  lv_obj_align(auton_title, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -85, -10);


  hold_label = lv_label_create(scr, NULL);
  lv_obj_set_style(hold_label, &title_style);
  lv_label_set_text(hold_label, "Brake Mode: \nCoast");
  lv_obj_align(hold_label, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 10);

  // Image//////////////////////////////////////////////////////////////////////

  static lv_point_t line_points[] = { {72,83}, {72,3}, {141,43}, {141,123}, {72,83}, {141,123}, {72,163}, {3,123}, {72,83}, {3,123}, {3,43}, {72,3} };
  static lv_point_t line_points2[] = { {3,43}, {37,63}, {72,43}, {107,63}, {141,43}, {107,63}, {107,103}, {72,123}, {72,163}, {72,123}, {37,103}, {37,63} };

  lv_style_copy(&line_style, &line_color);
  line_style.line.width = 3;

  line1 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_y_invert(line1, true);
  lv_line_set_style(line1, &line_style);
  lv_line_set_points(line1, line_points, 12);
  lv_obj_align(line1, NULL, LV_ALIGN_IN_LEFT_MID, 30, -20);

  line2 = lv_line_create(lv_scr_act(), line1);
  lv_line_set_points(line2, line_points2, 12);

  // buttons////////////////////////////////////////////////////////////////////

  lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label, 0, 0);

  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label2, 0, 0);

  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label3, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label3, 0, 0);

  lv_obj_t * label4 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label4, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label4, 0, 0);

  lv_obj_t * label5 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label5, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label5, 0, 0);

  lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL); // back red
  lv_cont_set_fit(btn1, true, true);
  lv_obj_set_size(btn1, 80, 40);
  lv_obj_align(btn1, label2, LV_ALIGN_CENTER, 147, -40);
  lv_obj_set_free_num(btn1, 1);
  lv_btn_set_toggle(btn1, true);
  lv_btn_set_action(btn1, LV_BTN_ACTION_PR, btn1_auton);
  lv_btn_set_style(btn1, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(btn1, LV_BTN_STYLE_TGL_PR, &button_style);

  lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), NULL); // front red
  lv_cont_set_fit(btn2, true, true);
  lv_obj_set_size(btn2, 40, 5);
  lv_obj_align(btn2, label, LV_ALIGN_IN_RIGHT_MID, 23, -40);
  lv_obj_set_free_num(btn2, 1);
  lv_btn_set_toggle(btn2, true);
  lv_btn_set_action(btn2, LV_BTN_ACTION_PR, btn2_auton);
  lv_btn_set_style(btn2, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(btn2, LV_BTN_STYLE_TGL_REL, &button_style);

  lv_obj_t * btn3 = lv_btn_create(lv_scr_act(), NULL); // front blue button
  lv_cont_set_fit(btn3, true, true);
  lv_obj_align(btn3, label3, LV_ALIGN_CENTER, 28, 15);
  lv_obj_set_free_num(btn3, 1);
  lv_btn_set_toggle(btn3, true);
  lv_btn_set_action(btn3, LV_BTN_ACTION_PR, btn3_auton);
  lv_btn_set_style(btn3, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(btn3, LV_BTN_STYLE_TGL_REL, &button_style);

  lv_obj_t * btn4 = lv_btn_create(lv_scr_act(), NULL);  // back blue button
  lv_cont_set_fit(btn4, true, true);
  lv_obj_set_size(btn4, 40, 5);
  lv_obj_align(btn4, label, LV_ALIGN_IN_RIGHT_MID, 146, 15);
  lv_obj_set_free_num(btn4, 1);
  lv_btn_set_toggle(btn4, true);
  lv_btn_set_action(btn4, LV_BTN_ACTION_PR, btn4_auton);
  lv_btn_set_style(btn4, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(btn4, LV_BTN_STYLE_TGL_REL, &button_style);

  lv_obj_t * btn5 = lv_btn_create(lv_scr_act(), NULL); // skills
  lv_cont_set_fit(btn5, true, true);
  lv_obj_set_size(btn5, 40, 5);
  lv_obj_align(btn5, label5, LV_ALIGN_IN_RIGHT_MID, 85, 62);
  lv_obj_set_free_num(btn5, 1);
  lv_btn_set_toggle(btn5, true);
  lv_btn_set_action(btn5, LV_BTN_ACTION_PR, btn5_auton);
  lv_btn_set_style(btn5, LV_BTN_STYLE_REL, &button_skills);
  lv_btn_set_style(btn5, LV_BTN_STYLE_TGL_REL, &button_style);

  label5 = lv_label_create(btn5, NULL);
  lv_label_set_text(label5, "Skills");

  label4 = lv_label_create(btn4, NULL);
  lv_label_set_text(label4, "Back Blue");

  label3 = lv_label_create(btn3, NULL);
  lv_label_set_text(label3, "Front Blue");

  label2 = lv_label_create(btn1, NULL);
  lv_label_set_text(label2, "Back Red");

  label = lv_label_create(btn2, NULL);
  lv_label_set_text(label, "Front Red");

  // animation//////////////////////////////////////////////////////////////////

  lv_anim_t a;
  a.var = line1;
  a.start = 0;
  a.end = 170;
  a.fp = (lv_anim_fp_t)lv_obj_set_height;
  a.path = lv_anim_path_linear;
  a.end_cb = NULL;
  a.act_time = 0;
  a.time = 1000;
  a.playback = 0;
  a.playback_pause = 0;
  a.repeat = 0;
  a.repeat_pause = 0;
  lv_anim_create(&a);

  lv_anim_t b;
  b.var = line2;
  b.start = 0;
  b.end = 170;
  b.fp = (lv_anim_fp_t)lv_obj_set_height;
  b.path = lv_anim_path_linear;
  b.end_cb = NULL;
  b.act_time = 0;
  b.time = 1000;
  b.playback = 0;
  b.playback_pause = 0;
  b.repeat = 0;
  b.repeat_pause = 0;
  lv_anim_create(&b);

  lv_anim_t c;
  c.var = line1;
  c.start = 0;
  c.end = 147;
  c.fp = (lv_anim_fp_t)lv_obj_set_width;
  c.path = lv_anim_path_linear;
  c.end_cb = NULL;
  c.act_time = 0;
  c.time = 500;
  c.playback = 1;
  c.playback_pause = 500;
  c.repeat = 1;
  c.repeat_pause = 750;
  lv_anim_create(&c);

  lv_anim_t d;
  d.var = line2;
  d.start = 0;
  d.end = 147;
  d.fp = (lv_anim_fp_t)lv_obj_set_width;
  d.path = lv_anim_path_linear;
  d.end_cb = NULL;
  d.act_time = 0;
  d.time = 500;
  d.playback = 1;
  d.playback_pause = 500;
  d.repeat = 1;
  d.repeat_pause = 0;
  lv_anim_create(&d);
}

////////////////////////////////////////// SIMPLE TEXT ///////////////////////////////////////////////////////

void simple_text() {
  static lv_style_t back_style;
  lv_style_copy(&back_style, &lv_style_plain);
  back_style.body.main_color = LV_COLOR_BLACK;
  back_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *screen = lv_obj_create(NULL, NULL);
  lv_obj_set_style(screen, &back_style);
  lv_scr_load(screen);

  // STYLES ///////////////////////////////////////////////////////////////////

  static lv_style_t word_style;
  lv_style_copy(&word_style, &lv_style_plain);
  word_style.text.font = &lv_font_dejavu_20;
  word_style.text.color = LV_COLOR_WHITE;

  static lv_style_t name_style;
  lv_style_copy(&name_style, &lv_style_plain);
  name_style.text.color = LV_COLOR_WHITE;
  name_style.text.font = &lv_font_dejavu_20;

  static lv_style_t lines_color;
  lv_style_copy(&lines_color, &lv_style_plain);
  lines_color.line.color = LV_COLOR_WHITE;

  static lv_color_t needle_colors[] = {LV_COLOR_WHITE};

  // TEXT //////////////////////////////////////////////////////////////////////

  hold_label = lv_label_create (screen, NULL);
  lv_obj_set_style(hold_label, &word_style);
  lv_obj_align(hold_label, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 0);

  // IMAGE /////////////////////////////////////////////////////////////////////

  static lv_point_t line_points[] = { {72,83}, {72,3}, {141,43}, {141,123}, {72,83}, {141,123}, {72,163}, {3,123}, {72,83}, {3,123}, {3,43}, {72,3} };
  static lv_point_t line_points2[] = { {3,43}, {37,63}, {72,43}, {107,63}, {141,43}, {107,63}, {107,103}, {72,123}, {72,163}, {72,123}, {37,103}, {37,63} };

  lv_style_copy(&line_style, &lv_style_plain);
  line_style.line.width = 3;
  line_style.line.color = LV_COLOR_WHITE;

  line1 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_y_invert(line1, true);
  lv_line_set_style(line1, &line_style);
  lv_line_set_points(line1, line_points, 12);
  lv_obj_align(line1, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0);

  line2 = lv_line_create(lv_scr_act(), line1);
  lv_line_set_points(line2, line_points2, 12);

  // ACTUAL IMAGE //////////////////////////////////////////////////////////////

  lv_obj_t * nameImg2 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(nameImg2, &simpletext);
  lv_obj_align(nameImg2, NULL, LV_ALIGN_CENTER, 85, 0);

  // ANIMATION /////////////////////////////////////////////////////////////////

  lv_anim_t a;
  a.var = line1;
  a.start = 0;
  a.end = 170;
  a.fp = (lv_anim_fp_t)lv_obj_set_height;
  a.path = lv_anim_path_linear;
  a.end_cb = NULL;
  a.act_time = 0;
  a.time = 1000;
  a.playback = 0;
  a.playback_pause = 0;
  a.repeat = 0;
  a.repeat_pause = 0;
  lv_anim_create(&a);

  lv_anim_t b;
  b.var = line2;
  b.start = 0;
  b.end = 170;
  b.fp = (lv_anim_fp_t)lv_obj_set_height;
  b.path = lv_anim_path_linear;
  b.end_cb = NULL;
  b.act_time = 0;
  b.time = 1000;
  b.playback = 0;
  b.playback_pause = 0;
  b.repeat = 0;
  b.repeat_pause = 0;
  lv_anim_create(&b);

  lv_anim_t c;
  c.var = line1;
  c.start = 0;
  c.end = 147;
  c.fp = (lv_anim_fp_t)lv_obj_set_width;
  c.path = lv_anim_path_linear;
  c.end_cb = NULL;
  c.act_time = 0;
  c.time = 500;
  c.playback = 1;
  c.playback_pause = 500;
  c.repeat = 1;
  c.repeat_pause = 750;
  lv_anim_create(&c);

  lv_anim_t d;
  d.var = line2;
  d.start = 0;
  d.end = 147;
  d.fp = (lv_anim_fp_t)lv_obj_set_width;
  d.path = lv_anim_path_linear;
  d.end_cb = NULL;
  d.act_time = 0;
  d.time = 500;
  d.playback = 1;
  d.playback_pause = 500;
  d.repeat = 1;
  d.repeat_pause = 0;
  lv_anim_create(&d);
}

/////////////////////////// BACK BLUE AUTON BUTTONS ////////////////////////////////////////////////////////////////////

void back_blue_autons() {

// BACKGROUND //////////////////////////////////////////////////////////////////

  static lv_style_t background_style;
  lv_style_copy(&background_style, &lv_style_plain);
  background_style.body.main_color = LV_COLOR_BLACK;
  background_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *scr = lv_obj_create(NULL, NULL);
  lv_obj_set_style(scr, &background_style);
    lv_scr_load(scr);

// STYLES //////////////////////////////////////////////////////////////////////

  static lv_style_t button_style;
  lv_style_copy(&button_style, &lv_style_plain);
  button_style.body.main_color = LV_COLOR_GREEN;
  button_style.body.grad_color = LV_COLOR_GREEN;
  button_style.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled;
  lv_style_copy(&button_toggled, &lv_style_plain);
  button_toggled.body.main_color = LV_COLOR_RED;
  button_toggled.body.grad_color = LV_COLOR_RED;
  button_toggled.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled2;
  lv_style_copy(&button_toggled2, &lv_style_plain);
  button_toggled2.body.main_color = LV_COLOR_BLUE;
  button_toggled2.body.grad_color = LV_COLOR_BLUE;
  button_toggled2.text.color = LV_COLOR_WHITE;

// LABELS //////////////////////////////////////////////////////////////////////

  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label2, 0, 0);

  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label3, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label3, 0, 0);

// BUTTONS /////////////////////////////////////////////////////////////////////

  lv_obj_t * btn6 = lv_btn_create(lv_scr_act(), NULL); // back blue far flags with park
  lv_cont_set_fit(btn6, false, false);
  lv_obj_set_size(btn6, 120, 100);
  lv_obj_align(btn6, label2, LV_ALIGN_OUT_TOP_LEFT, -200, 12);
  lv_obj_set_free_num(btn6, 1);
  lv_btn_set_toggle(btn6, true);
  lv_btn_set_action(btn6, LV_BTN_ACTION_CLICK, btn6_auton);
  lv_btn_set_style(btn6, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(btn6, LV_BTN_STYLE_TGL_PR, &button_style);


  lv_obj_t * back = lv_btn_create(lv_scr_act(), NULL); // BACK BUTTON
  lv_cont_set_fit(back, true, true);
  lv_obj_set_size(back, 120, 100);
  lv_obj_align(back, label3, LV_ALIGN_OUT_TOP_LEFT, -30, 130);
  lv_obj_set_free_num(back, 1);
  lv_btn_set_toggle(back, true);
  lv_btn_set_action(back, LV_BTN_ACTION_CLICK, back_but);
  lv_btn_set_style(back, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(back, LV_BTN_STYLE_TGL_PR, &button_style);

  label3 = lv_label_create(back, NULL);
  lv_label_set_text(label3, "BACK");

  label2 = lv_label_create(btn6, NULL);
  lv_label_set_text(label2, "Far Flags\nand Park(12)");

}

/////////////////////////////////// FRONT RED AUTON BUTTONS /////////////////////////////////////////////////////////////////////////

void frontRed_autons() {

// BACKGROUND //////////////////////////////////////////////////////////////////

  static lv_style_t background_style;
  lv_style_copy(&background_style, &lv_style_plain);
  background_style.body.main_color = LV_COLOR_BLACK;
  background_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *scr = lv_obj_create(NULL, NULL);
  lv_obj_set_style(scr, &background_style);
    lv_scr_load(scr);

// STYLES //////////////////////////////////////////////////////////////////////

  static lv_style_t button_style;
  lv_style_copy(&button_style, &lv_style_plain);
  button_style.body.main_color = LV_COLOR_GREEN;
  button_style.body.grad_color = LV_COLOR_GREEN;
  button_style.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled;
  lv_style_copy(&button_toggled, &lv_style_plain);
  button_toggled.body.main_color = LV_COLOR_RED;
  button_toggled.body.grad_color = LV_COLOR_RED;
  button_toggled.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled2;
  lv_style_copy(&button_toggled2, &lv_style_plain);
  button_toggled2.body.main_color = LV_COLOR_BLUE;
  button_toggled2.body.grad_color = LV_COLOR_BLUE;
  button_toggled2.text.color = LV_COLOR_WHITE;

// LABELS //////////////////////////////////////////////////////////////////////

  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label2, 0, 0);

  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label3, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label3, 0, 0);

// BUTTONS /////////////////////////////////////////////////////////////////////

  lv_obj_t * btn9 = lv_btn_create(lv_scr_act(), NULL); // FRONT RED CLOSE 9
  lv_cont_set_fit(btn9, false, false);
  lv_obj_set_size(btn9, 120, 100);
  lv_obj_align(btn9, label2, LV_ALIGN_OUT_TOP_LEFT, -200, 12);
  lv_obj_set_free_num(btn9, 1);
  lv_btn_set_toggle(btn9, true);
  lv_btn_set_action(btn9, LV_BTN_ACTION_CLICK, btn9_auton);
  lv_btn_set_style(btn9, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(btn9, LV_BTN_STYLE_TGL_PR, &button_style);

  lv_obj_t * back = lv_btn_create(lv_scr_act(), NULL); // BACK BUTTON
  lv_cont_set_fit(back, true, true);
  lv_obj_set_size(back, 120, 100);
  lv_obj_align(back, label3, LV_ALIGN_OUT_TOP_LEFT, -30, 130);
  lv_obj_set_free_num(back, 1);
  lv_btn_set_toggle(back, true);
  lv_btn_set_action(back, LV_BTN_ACTION_CLICK, back_but);
  lv_btn_set_style(back, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(back, LV_BTN_STYLE_TGL_PR, &button_style);

  label3 = lv_label_create(back, NULL);
  lv_label_set_text(label3, "BACK");

  label2 = lv_label_create(btn9, NULL);
  lv_label_set_text(label2, "Left Flags\nnd middle(9)");
}

/////////////////////////////////////////////// FRONT BLUE AUTON BUTTONS //////////////////////////////////////////////////////////

void frontBlue_autons() {

// BACKGROUND //////////////////////////////////////////////////////////////////

  static lv_style_t background_style;
  lv_style_copy(&background_style, &lv_style_plain);
  background_style.body.main_color = LV_COLOR_BLACK;
  background_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *scr = lv_obj_create(NULL, NULL);
  lv_obj_set_style(scr, &background_style);
    lv_scr_load(scr);

// STYLES //////////////////////////////////////////////////////////////////////

  static lv_style_t button_style;
  lv_style_copy(&button_style, &lv_style_plain);
  button_style.body.main_color = LV_COLOR_GREEN;
  button_style.body.grad_color = LV_COLOR_GREEN;
  button_style.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled;
  lv_style_copy(&button_toggled, &lv_style_plain);
  button_toggled.body.main_color = LV_COLOR_RED;
  button_toggled.body.grad_color = LV_COLOR_RED;
  button_toggled.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled2;
  lv_style_copy(&button_toggled2, &lv_style_plain);
  button_toggled2.body.main_color = LV_COLOR_BLUE;
  button_toggled2.body.grad_color = LV_COLOR_BLUE;
  button_toggled2.text.color = LV_COLOR_WHITE;

// LABELS //////////////////////////////////////////////////////////////////////

  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label2, 0, 0);

  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label3, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label3, 0, 0);

// BUTTONS /////////////////////////////////////////////////////////////////////

  lv_obj_t * btn11 = lv_btn_create(lv_scr_act(), NULL); // FRONT BLUE CLOSE 9
  lv_cont_set_fit(btn11, false, false);
  lv_obj_set_size(btn11, 120, 100);
  lv_obj_align(btn11, label2, LV_ALIGN_OUT_TOP_LEFT, -200, 12);
  lv_obj_set_free_num(btn11, 1);
  lv_btn_set_toggle(btn11, true);
  lv_btn_set_action(btn11, LV_BTN_ACTION_CLICK, btn11_auton);
  lv_btn_set_style(btn11, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(btn11, LV_BTN_STYLE_TGL_PR, &button_style);

  lv_obj_t * back = lv_btn_create(lv_scr_act(), NULL); // BACK BUTTON
  lv_cont_set_fit(back, true, true);
  lv_obj_set_size(back, 120, 100);
  lv_obj_align(back, label3, LV_ALIGN_OUT_TOP_LEFT, -30, 130);
  lv_obj_set_free_num(back, 1);
  lv_btn_set_toggle(back, true);
  lv_btn_set_action(back, LV_BTN_ACTION_CLICK, back_but);
  lv_btn_set_style(back, LV_BTN_STYLE_REL, &button_toggled2);
  lv_btn_set_style(back, LV_BTN_STYLE_TGL_PR, &button_style);

  label3 = lv_label_create(back, NULL);
  lv_label_set_text(label3, "BACK");

  label2 = lv_label_create(btn11, NULL);
  lv_label_set_text(label2, "Left Flags\nnd middle(9)");
}

///////////////////////////////////////////// BACK RED AUTON BUTTONS /////////////////////////////////////////////////////////////////

void backRed_autons() {

// BACKGROUND //////////////////////////////////////////////////////////////////

  static lv_style_t background_style;
  lv_style_copy(&background_style, &lv_style_plain);
  background_style.body.main_color = LV_COLOR_BLACK;
  background_style.body.grad_color = LV_COLOR_BLACK;

  lv_obj_t *scr = lv_obj_create(NULL, NULL);
  lv_obj_set_style(scr, &background_style);
    lv_scr_load(scr);

// STYLES //////////////////////////////////////////////////////////////////////

  static lv_style_t button_style;
  lv_style_copy(&button_style, &lv_style_plain);
  button_style.body.main_color = LV_COLOR_GREEN;
  button_style.body.grad_color = LV_COLOR_GREEN;
  button_style.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled;
  lv_style_copy(&button_toggled, &lv_style_plain);
  button_toggled.body.main_color = LV_COLOR_RED;
  button_toggled.body.grad_color = LV_COLOR_RED;
  button_toggled.text.color = LV_COLOR_WHITE;

  static lv_style_t button_toggled2;
  lv_style_copy(&button_toggled2, &lv_style_plain);
  button_toggled2.body.main_color = LV_COLOR_BLUE;
  button_toggled2.body.grad_color = LV_COLOR_BLUE;
  button_toggled2.text.color = LV_COLOR_WHITE;

// LABELS //////////////////////////////////////////////////////////////////////

  lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label, 0, 0);

  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label2, 0, 0);

  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(label3, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_size(label3, 0, 0);

// BUTTONS /////////////////////////////////////////////////////////////////////

  lv_obj_t * btn13 = lv_btn_create(lv_scr_act(), NULL); // BACK RED FAR FLAGS 12
  lv_cont_set_fit(btn13, false, false);
  lv_obj_set_size(btn13, 120, 100);
  lv_obj_align(btn13, label2, LV_ALIGN_OUT_TOP_LEFT, -200, 12);
  lv_obj_set_free_num(btn13, 1);
  lv_btn_set_toggle(btn13, true);
  lv_btn_set_action(btn13, LV_BTN_ACTION_CLICK, btn13_auton);
  lv_btn_set_style(btn13, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(btn13, LV_BTN_STYLE_TGL_PR, &button_style);

  lv_obj_t * back = lv_btn_create(lv_scr_act(), NULL); // BACK BUTTON
  lv_cont_set_fit(back, true, true);
  lv_obj_set_size(back, 120, 100);
  lv_obj_align(back, label3, LV_ALIGN_OUT_TOP_LEFT, -30, 130);
  lv_obj_set_free_num(back, 1);
  lv_btn_set_toggle(back, true);
  lv_btn_set_action(back, LV_BTN_ACTION_CLICK, back_but);
  lv_btn_set_style(back, LV_BTN_STYLE_REL, &button_toggled);
  lv_btn_set_style(back, LV_BTN_STYLE_TGL_PR, &button_style);

  label3 = lv_label_create(back, NULL);
  lv_label_set_text(label3, "BACK");

  label2 = lv_label_create(btn13, NULL);
  lv_label_set_text(label2, "Far Flags\nand Park(12)");
}
