import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] ips = new int[n];
        
        for (int i = 0; i < n; i++) {
            ips[i] = ipToInt(sc.next());
        }
        
        int network = ips[0];
        int mask = 0xFFFFFFFF;
        
        // IP 중 가장 작은 것과 가장 큰 것을 찾음
        int minIp = ips[0];
        int maxIp = ips[0];
        for (int ip : ips) {
            minIp = Math.min(minIp, ip);
            maxIp = Math.max(maxIp, ip);
        }
        
        // minIp와 maxIp가 같을 때까지 마스크를 줄여 나감
        while ((minIp & mask) != (maxIp & mask)) {
            mask <<= 1;
        }
        
        network = minIp & mask;
        
        System.out.println(intToIp(network));
        System.out.println(intToIp(mask));
    }

    // IP 문자열을 정수로 변환
    private static int ipToInt(String ip) {
        String[] parts = ip.split("\\.");
        int res = 0;
        for (int i = 0; i < 4; i++) {
            res = (res << 8) | Integer.parseInt(parts[i]);
        }
        return res;
    }

    // 정수를 IP 문자열로 변환
    private static String intToIp(int num) {
        return String.format("%d.%d.%d.%d", 
                             (num >> 24) & 0xFF, 
                             (num >> 16) & 0xFF, 
                             (num >> 8) & 0xFF, 
                             num & 0xFF);
    }
}
