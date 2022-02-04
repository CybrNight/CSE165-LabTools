#Create new folder structure
#!/bin/bash

echo "This will setup the folder structure for the lab"

if [ -d $i ] ; then
        echo "Setup already done. Abort."
        exit
    else

for i in `seq 1 6`; do
    mkdir $i
    cp "resource/template.cpp" $i/$i.cpp        
    fi;
done

#Move existing files if desired