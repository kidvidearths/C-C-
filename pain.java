import java.io.File;
public class pain
{
   static void deleteFolder(File file)
   {
      for (File subFile : file.listFiles())
      {
         if(subFile.isDirectory())
         {
            deleteFolder(subFile);
         }
         else
         {
            subFile.delete();
         }
      }
      file.delete();
   }
   public static void main(String args[])
   {
      String filePath = "/Users/RamaReddi/Jala";
      File file = new File(filePath);
      for (File subFile : file.listFiles())
      {
         if (subFile.isDirectory())
         {
            for (File subsub : subFile.listFiles())
            {
               if (subsub.isDirectory())
               {
                  deleteFolder(subsub);
               }
            }
         }
      }
      System.out.println("Files deleted........");
   }
}