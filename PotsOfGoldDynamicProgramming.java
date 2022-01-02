/*Pots of Gold Game Problem using Dynamic Programming
There are two players, A and B, in Pots of gold game, and pots of gold arranged in a line,
each containing some gold coins. The players can see how many coins are there in each gold
pot, and each player gets alternating turns in which the player can pick a pot from either
end of the line. The winner is the player who has a higher number of coins at the end.
The objective is to “maximize” the number of coins collected by A, assuming B also plays 
“optimally”, and A starts the game.*/

import java.util.*;
public class PotsOfGoldDynamicProgramming{
    public static int potsOfGold(int []coins, int i, int j)
    {
        if(i==j) return coins[i];

        if(i+1==j) return Math.max(coins[i],coins[j]);


        //if player puts coins from "i" then opponent remain with [i+1, j] coins 
        //1) if opponent choose "i+1" recur to [i+2,j]
        //2) if opponent choose " j" recur to [i+1,j-1]
        int start = coins[i] + Math.max(potsOfGold(coins, i+2, j),potsOfGold(coins, i+1, j-1));


        //if player puts coins from "j" then opponent remain with [i, j-1] coins 
        //1) if opponent choose "i" recur to [i+1,j-1]
        //2) if opponent choose "j-1" recur to [i,j-2]
        int end = coins[j] + Math.max(potsOfGold(coins, i+1, j-1),potsOfGold(coins, i, j-2));

        return Math.max(start, end);
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []coins = new int[n];
        for(int i=0;i<n;i++)
        {
            coins[i] = sc.nextInt();
        }
        System.out.println(potsOfGold(coins, 0, n-1));
        sc.close();
    }
}