#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

// splash screen resource
#define SPLASH_STATE_SHOW_TIME 2.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

// main menu resource
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

// game resource
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"

// game over
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky.png"

// pipes
#define PIPE_UP_BACKGROUND_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_BACKGROUND_FILEPATH "Resources/res/PipeDown.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

// land
#define LAND_FILEPATH "Resources/res/land.png"

// bird
#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f
#define ROTATION_LIMIT 25.0f

#define GRAVITY 350.0f

// game states
enum GameStates
{
    eReady,
    ePlaying,
    eGameOver
};

#define FLASH_SPEED 1500.0f

// gamescore
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define HIGHSCORE_FILE_PATH "Resources/Highscore.txt"

#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 10
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

// gameover title
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

// game sounds
#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"

#endif // DEFINITIONS_H
