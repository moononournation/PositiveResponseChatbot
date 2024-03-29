typedef struct
{
    uint8_t count;
    uint8_t ids[8];
} responseData;

responseData responseMap[20] = {
    {1, {16, 99, 99, 99, 99, 99, 99, 99}}, // 10000	早晨
    {2, {26, 27, 99, 99, 99, 99, 99, 99}}, // 10001	你好
    {2, {11, 15, 99, 99, 99, 99, 99, 99}}, // 10002	再見
    {2, {11, 15, 99, 99, 99, 99, 99, 99}}, // 10003	拜拜
    {5, {10, 17, 45, 50, 54, 99, 99, 99}}, // 10004	正
    {7, {10, 17, 19, 41, 43, 52, 99, 99}}, // 10005	好勁
    {5, {10, 17, 20, 50, 56, 99, 99, 99}}, // 10006	好叻
    {6, {10, 17, 21, 44, 50, 53, 99, 99}}, // 10007	好味
    {3, {10, 17, 55, 99, 99, 99, 99, 99}}, // 10008	好攰
    {5, {10, 17, 22, 38, 50, 99, 99, 99}}, // 10009	好熱
    {5, {10, 17, 18, 40, 50, 99, 99, 99}}, // 10010	好凍
    {8, {10, 17, 28, 39, 46, 48, 49, 58}}, // 10011	好開心
    {4, {26, 28, 35, 47, 99, 99, 99, 99}}, // 10012	好唔開心
    {2, {42, 57, 99, 99, 99, 99, 99, 99}}, // 10013	乜野
    {5, {10, 17, 30, 36, 42, 99, 99, 99}}, // 10014	係咪
    {3, {36, 37, 42, 99, 99, 99, 99, 99}}, // 10015	點算
    {3, {37, 42, 51, 99, 99, 99, 99, 99}}, // 10016	點解
    {5, {13, 14, 36, 37, 42, 99, 99, 99}}, // 10017	好唔好
    {7, {10, 17, 29, 31, 32, 33, 34, 99}}, // 10018	痴線
    {6, {12, 17, 23, 24, 25, 52, 99, 99}}  // 10019	我係咪好勁
};

/*
係呀: 10.mp3
再見: 11.mp3
唔係: 12.mp3
唔好: 13.mp3
好呀: 14.mp3
拜拜: 15.mp3
早晨: 16.mp3
係呀2: 17.mp3
好凍咩: 18.mp3
好勁咩: 19.mp3
好叻呀: 20.mp3
好味咩: 21.mp3
好熱咩: 22.mp3
算吧啦: 23.mp3
講呢啲1: 24.mp3
講呢啲2: 25.mp3
一齊玩啦: 26.mp3
你幾好嘛: 27.mp3
做乜嘢呀: 28.mp3
唔好嬲啦: 29.mp3
我唔係呀: 30.mp3
痴線蜘蛛1: 31.mp3
痴線蜘蛛2: 32.mp3
痴線蜘蛛3: 33.mp3
痴線蜘蛛4: 34.mp3
做乜嘢事呀: 35.mp3
我冇所謂架: 36.mp3
我都唔知呀: 37.mp3
我都好熱呀: 38.mp3
我都好開心: 39.mp3
著多件衫呀: 40.mp3
邊個好勁呀: 41.mp3
咁我又唔知喎: 42.mp3
我覺得唔係囉: 43.mp3
我都想試吓呀: 44.mp3
我都覺得好靚: 45.mp3
點解咁開心呀: 46.mp3
點解唔開心呀: 47.mp3
你開心我都開心: 48.mp3
你點解咁開心呀: 49.mp3
係呀我都得係咁: 50.mp3
我都唔知點解喎: 51.mp3
我都覺得好勁呀: 52.mp3
我都覺得好味呀: 53.mp3
我都覺得好正啦: 54.mp3
我幫你按摩膊頭吖: 55.mp3
係呀我都覺得好叻呀: 56.mp3
我都唔知道乜嘢嚟架: 57.mp3
有咩事覺得咁開心呀: 58.mp3
*/
