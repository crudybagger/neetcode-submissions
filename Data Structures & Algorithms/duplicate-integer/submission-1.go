func hasDuplicate(nums []int) bool {
    st := make(map[int]bool);
    for i := 0; i < len(nums); i++ {
        // _, exists := st[nums[i]];
        if(st[nums[i]]) { 
            return true;
        } else {
            st[nums[i]] = true;
        }
    }
    return false;
}
