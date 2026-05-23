import java.util.*;
import java.io.*;

public class p2{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int t = Integer.parseInt(r.readLine());

        for(int test = 0; test < t; test++){
            int n = Integer.parseInt(r.readLine());
            StringTokenizer st = new StringTokenizer(r.readLine());
            int[] nums = new int[n];
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }

            ArrayList<int[]> maxOne = new ArrayList<>();
            ArrayList<int[]> maxTwo = new ArrayList<>();
            int diff = 0;

            boolean flag = false;

            for(int i = 0; i < n; i++){
                if(maxOne.isEmpty() || nums[i] >= maxOne.get(maxOne.size() - 1)[0]){
                    maxOne.add(new int[]{nums[i], i});
                }else if(maxTwo.isEmpty() || nums[i] >= maxTwo.get(maxTwo.size() - 1)[0]){
                    diff = Math.max(diff, maxOne.get(maxOne.size() - 1)[0] - nums[i]);
                    maxTwo.add(new int[]{nums[i], i});
                }else{
                    flag = true;
                    break;
                }
            }
            for(int[] e : maxTwo){
                nums[e[1]] += diff;
            }
            for(int i = 1; i < n; i ++){
                if(nums[i - 1] > nums[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                pw.println("NO");
            }else{
                pw.println("YES");
            }
        }
        pw.close();
    }
}