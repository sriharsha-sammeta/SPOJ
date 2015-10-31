if(Test-path $args\$args\Source.cpp){
    echo "$args.cpp File exists\n"
    echo "moving it ...\n"    
    Copy $args\$args\Source.cpp .\$args.cpp
    echo "deleting the $args directory...\n"
    Remove-Item .\$args -Recurse -Force
    }else{
echo "$args\$args\Source.cpp not found"
}