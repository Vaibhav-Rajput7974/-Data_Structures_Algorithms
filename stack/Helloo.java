import java.lang.*;
public class Helloo{
    public static void main(String[] args) {
        String[] str = {"1","2","3","c","d","+"};

        int[] rrr = new int[str.length];
        int end = -1;
        for(int i=0; i<str.length; i++){



            if(str[i].charAt(i) == 0 || 
            str[i].charAt(i) == 1 ||
            str[i].charAt(i) == 2 ||
            str[i].charAt(i) == 3 ||
            str[i].charAt(i) == 4 ||
            str[i].charAt(i) == 5 ||
            str[i].charAt(i) == 6 ||
            str[i].charAt(i) == 7 ||
            str[i].charAt(i) == 8 ||
            str[i].charAt(i) == 9 ){
                end++;
                try {
                    rrr[end] =   Integer.parseInt( (str[i].charAt(i)) ); 
                    
                } catch (Exception e) {
                    System.out.println("Exception");
                }
            }


        }



    }
}