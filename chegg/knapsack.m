bestBoxes=[];
bestValue=0;
weight=[8,3,4,1,5,9,6,7,2];
value=[6,1,8,7,5,3,2,9,4];
indices=[1,2,3,4,5,6,7,8,9];
for sizes=1:9
    allpossiblechoices = nchoosek(indices,sizes);
    for i=1:size(allpossiblechoices,1)
        currentBoxes=allpossiblechoices(i,:);
        currentweight=sum(weight(currentBoxes));
        currentvalue=sum(value(currentBoxes));
        if currentvalue>bestValue && currentweight<15
            bestValue=currentvalue;
            bestBoxes=currentBoxes;
        end
    end
end
disp("Best boxes to select: ");
disp(bestBoxes);
disp("Best Value to get: "+bestValue);
