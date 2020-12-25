import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * String input, int currentPiece, int numOfStick;\
 * 1. input을 순회
 * 2. input의 i와 i+1의 값을 보고 쇠막대기의 시작값인지, 레이저인지 구분한다.
 * 2.1. i가 '(' && i+1이 ')' => 쇠막대기
 * 2.2. i가 '(' && i+1이 '(' => 새 막대기 시작
 * 2.3. i가 ')'이면 i-1을 보고 판단. i-1이 '('면 레이저이므로 무시
 * 2.4.                                 ')'이면 막대기가 끝난 위치이므로 currentPiece--, numOfStick++(남은 짜투리 더하기)
 */
public class Main_Baekjoon_10799_쇠막대기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int len = input.length();
        int currentPiece = 0, numOfStick = 0;

        // 1. input 순회
        for (int i = 0; i < len; i++) {
            // 2. 레이저인지 쇠막대기인지 판단
            if (input.charAt(i) == '(') {
                if (input.charAt(i + 1) == ')') {//레이저
                    numOfStick += currentPiece; // 잘린 막대의 갯수 더해주기
                } else {//새로운 새막대기
                    currentPiece++; // 막대기 겹치기
                }
            }else if(i > 0 && input.charAt(i) == ')'){
                if(input.charAt(i-1) == ')'){ // 쇠막대기의 끝
                    numOfStick++; // 남은 조각 더해주기
                    currentPiece--;
                }
            }
        }

        System.out.println(numOfStick);

    }// end of main
}// end of class
