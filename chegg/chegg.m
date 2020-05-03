list=search('course_data.txt','CIVE105');
disp(list);

function y = search(filename,coursename)
    fid = fopen(filename);
    cell_array=[];
    line = fgetl(fid);
    while ischar(line)
        if(isempty(line))
           break; 
        end
        results = strfind(line,coursename);
        if(not(isempty(results)))
           cell_array =[cell_array, extractBetween(line,1,results(1)-1)];
        end
        line = fgetl(fid);
    end
    y=cell_array;
end