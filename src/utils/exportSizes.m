fileID = fopen('sizes.txt', 'w');
fprintf(fileID, "int sizes = [");
for i = 0:25
  quad = [];
  quad = tableQuadTri(i);
  rows = size(quad,1);
  fprintf(fileID, "%d,", rows);
end
fprintf(fileID,"]");
fclose(fileID);