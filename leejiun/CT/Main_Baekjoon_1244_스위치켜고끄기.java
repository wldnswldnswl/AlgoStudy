import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 1남학생은 스위치 번호가 자기가 받은 수의 배수이면,
// 2자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간
public class Main_Baekjoon_1244_스위치켜고끄기 {
    private static int N;
    private static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N+1];

        for (int i = 1; i < N+1; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }// 스위치 입력

        int numOfPeople = Integer.parseInt(br.readLine());
        for (int i = 0; i < numOfPeople; i++) {// 학생의 동작 수행
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int switchNumber = Integer.parseInt(st.nextToken());

            if(gender == 1){// 남자
                배수이면바꾸기(switchNumber);
            }else{//여자
                대칭이일치하면바꾸기(switchNumber);
            }
        }

        for(int i = 1; i < N+1;i++){
            System.out.print(arr[i]+" ");
            if(i % 20 == 0){
                System.out.println();
            }
        }
    }

    private static void 대칭이일치하면바꾸기(int switchNumber) {
        int i = 1;
        int range = N/2;

        changeNumber(switchNumber);//중심숫자는 무조건 바꾸기
        while(i > 0 && i <= range){
            if(isRange(switchNumber,i) && arr[switchNumber-i] == arr[switchNumber+i]){
                changeNumber(switchNumber-i);
                changeNumber(switchNumber+i);
                i++;
            }else break;
        }
    }

    private static boolean isRange(int switchNumber, int i) {
        return switchNumber - i > 0 && switchNumber + i <= N;
    }

    private static void 배수이면바꾸기(int switchNumber) {
        for (int j = 1; j < N+1; j++) {
            if(j%switchNumber == 0){
                changeNumber(j);
            }
        }
    }

    private static void changeNumber(int num) {
        arr[num] = (arr[num] == 0)?1:0;
    }
}
