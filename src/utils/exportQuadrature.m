fileID = fopen('tableQuadTri.txt', 'w');
for i = 0:25
  quad = [];
  quad = tableQuadTri(i);
  for j = 1:size(quad,1)
    fprintf(fileID, "%f, %f, %f, %f\n", quad(j,:));
  end
  fprintf(fileID, "\n\n");
end
fclose(fileID);