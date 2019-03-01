    <?php
    
    $t = fgets(STDIN);
    $t = explode(" ",$t);
    $n = (int)$t[0];
    $m = (int)$t[1];
     
    $a = [];
    $a = array_fill(0,m+1,0);
     
    while($n > 0)
    {
        $t = fgets(STDIN);
        $t = explode(" ",$t);
        $p = (int)$t[0];
        $b = (int)$t[1];
        
        if($a[$b] < $p)
            $a[$b] = $p;
        
        $n--;
    }
    $ans = 0;
    for($i = 0; $i <= $m; $i++)
        $ans = $a[$i] + $ans;
        
    echo $ans;
     
    ?>
