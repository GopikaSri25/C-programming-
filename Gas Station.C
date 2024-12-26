int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int gas_tank = 0, start_index = 0, sum = 0;
        
        for (int i=0; i<costSize; i++) {
            
            sum += gas[i] - cost[i];
            gas_tank += gas[i] - cost[i];
            
            if (gas_tank < 0) {
                start_index = i+1;
                gas_tank = 0;
            }
            
        }
        return sum < 0 ? -1 : start_index;
}
