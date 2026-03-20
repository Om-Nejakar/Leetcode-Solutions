class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coin5 = 0;
        int coin10 = 0;
        int coin20 = 0;

        for(int i=0;i<bills.size();i++) {
            if(bills[i] == 5) {
                coin5++;
            }else if(bills[i] == 10) {
                coin10++;
            }else {
                coin20++;
            }

            int change = bills[i]-5; //to give the change 

            while(change > 0) {
                if(change >= 20) {
                    int reqcoins = change/20;
                    if(coin20 && coin10 >= reqcoins) {
                        coin20 -= reqcoins;
                        change = change%20;
                    }
                }
                if(change >= 10) {
                    int reqcoins = change/10;
                    if(coin10 && coin10 >= reqcoins) {
                        coin10 -= reqcoins;
                        change = change%10;
                    }
                }
                if(change >= 5) {
                    int reqcoins = change/5;
                    if(coin5 && coin5 >= reqcoins) {
                        coin5 -= reqcoins;
                        change = change%5;
                    }else {
                        return false;
                    }
                }

            }
        }
        return true;
    }
};