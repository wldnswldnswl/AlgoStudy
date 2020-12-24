import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
// https://pangsblog.tistory.com/53
// 나와 같은 논리
// 보고 고쳐보기
public class Main_Baekjoon_2504_괄호의값 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));
        String input = br.readLine();//입력
        int len = input.length();
        Stack<Character> st = new Stack<Character>();

        int weight = 0;
        boolean open = false;
        for (int i = 0; i < len; i++) {
            char currentChar = input.charAt(i);

            switch (currentChar){
                // 여는 괄호
                case '(':
                case '[':
                    open = true;
                    st.push(currentChar);
                    break;
                // 닫는 괄호
                case ')':
                    if(!open){
                        System.out.println(0);
                        return;
                    }

                    while(!st.isEmpty()){
                        // 넣어놓은 여는 괄호 만날 때 까지
                        char item = st.pop();
                        if(item == '('){
                            if(weight == 0) weight = 1;
                            st.push((char) (2*weight));
                            weight = 0;

                        }else if(isNumber(item)){
                            weight += item-'\0';
                        }
                        else {
                            System.out.println(0);
                            return;
                        }
                        open = false;
                        break;
                    }
                    break;
                case ']':
                    if(!open){
                        System.out.println(0);
                        return;
                    }

                    while(!st.isEmpty()){
                        // 넣어놓은 여는 괄호 만날 때 까지
                        char item = st.pop();
                        if(item == '['){
                            if(weight == 0) weight = 1;
                            st.push((char)(3*weight));
                            weight = 0;
                        }else if(isNumber(item)){
                            weight += item-'\0';
                        }
                        else{
                            System.out.println(0);
                            return;
                        }
                        open = false;
                        break;
                    }
                    break;
                default:
                    System.out.println(0);
                    return;

            }
        }

        int result = 0;
        while(!st.isEmpty()){
            char ch = st.pop();
            if(!isNumber(ch)){
                System.out.println(0);
                return;
            }
            result += (ch-'\0');
        }

        System.out.println(result);




    }// end of main

    // 두 괄호가 아니면 무조건 숫자이다.
    public static boolean isNumber(char ch) {
        if(ch == ')' ||  ch == ']' || ch == '(' || ch == '[' || ch == '{' || ch == '}') return false;
        return true;
    }
}// end of class
