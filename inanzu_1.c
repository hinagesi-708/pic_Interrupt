#define T0INT_OCCURED 1
#define T1INT_OCCURED 2
#define T2INT_OCCURED 4
volatile int FlagAndStatus; //どれが割り込んだかを示すビットマップ

main(){
	while(1){
		if (FlagAndStatus> 0){
			if(FlagAndStatus & T0INT_OCCURED) {
				FlagAndStatus = FlagAndStatus & (~(T0INT_OCCURED))
				//T0INT_OCCUREDのビット反転したもの(~T0INT_OCCURED)でANDして、フラグを1ビットだけ消す
				//消す処理を入れないとwhileループ中ずっと呼ばれてしまうし、0を入れると他のフラグも潰れてしまう。
				//T0INT_OCCUREDをかっこで囲ってあるのは、T0INT_OCCUREDに計算式が含まれた時、演算順所が想定外になってバグるのを防ぐため。

				/*処理*/

			}
			if(FlagAndStatus & T1INT_OCCURED) {
				FlagAndStatus = FlagAndStatus & (~(T1INT_OCCURED)) //同じ
				/*処理*/
			}

			if(FlagAndStatus & T2INT_OCCURED) {
				FlagAndStatus = FlagAndStatus & (~(T2INT_OCCURED)) //同じ
				/*処理*/
			}
		}
	}
}
void interrupt T0INT(void){
	if(1==T0IF){
	FlagAndStatus = FlagAndStatus | (T0INT_OCCURED); //ビットORを使ってT0INT_OCCUREDフラグだけ建てる
	}
}
void interrupt T1INT(void){
	if(1==T1IF){
	FlagAndStatus = FlagAndStatus | (T1INT_OCCURED);
	}
}
void interrupt T2INT(void){
	if(1==T2IF){
	FlagAndStatus = FlagAndStatus | (T2INT_OCCURED); 
	}
}
