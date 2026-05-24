import java.util.*;
import java.io.*;

public class p1{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(r.readLine());

        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(r.readLine());
            StringBuilder sb = new StringBuilder();

            int offset = 0;

            for(int j = 0; j < n; j++){
                if((j + 1 + offset)%3 == 0){
                    offset ++;
                }
                sb.append(j + 1 + offset).append(" ");
            }

            pw.println(sb);
        }

        pw.close();
    }
}