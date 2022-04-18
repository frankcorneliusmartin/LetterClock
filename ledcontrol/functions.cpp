#include "functions.h"


void the_matrix_animation(LedControl lc, int n, int m){

    Serial.println("------------------------------------------");
    Serial.println("Start the matix");
    Serial.println("------------------------------------------");

    // horizontal start index
    int i = rand() % 6;

    // length of the string between 4-13
    int l = (rand() % 5) + 4;



    // compute the range of the snake
    int max_i, min_i;
    max_i = min_i = 0;

    // for as long as the snake is in the display
    while (min_i < 6){
        // Serial.println((String)"max_i: "+max_i);
        // set initial state
        bool column[6] = { 0 };

        // compute the snake
        min_i = max_i + 1 - l;
        min_i = (min_i < 0) ? 0 : min_i;
        for(int i=min_i; i<max_i; i++){
            column[i] = 1;
        }
        // Serial.println((String)"max_i: "+max_i);
        // update display
        int encoding = snake_encode(column);
        Serial.println(encoding);
        Serial.println(i);

        lc.setRow(0, i, encoding);
        delay(20);

        // move the snake one possition forward
        max_i += 1;

        // when the snake reaches the end
        if (max_i > 6){
            max_i = 6;
            l -= 1;
        }

        // Serial.println((String)"min_i: "+min_i);
        // Serial.println((String)"max_i: "+max_i);
        // Serial.println((String)"l: "+l);
        // Serial.println((String)"encoding: "+encoding);

        // Serial.println((String)"condition: "+(min_i < 7));

    }

    return;

}

// int snake_length(bool column[8]){
//     int sum = 0;
//     for(int i=0; i<8; i++){
//         if(column[i]){
//             sum += 1;
//         }
//     }
// }

int snake_encode(bool column[6]){
    //int encode[8] = {128,64,32,16,8,4,2,1};
    // int encode[6] = {128,64,32,16,8,4};
    // int encode[6] = {128,64,32,16,8,4};
    int encode[6] = {4,8,16,32,64,128};
    int code = 0;
    for(int i=0; i<6; i++){
        if(column[i]){
            code += encode[i];
        }
    }
    return code;
}