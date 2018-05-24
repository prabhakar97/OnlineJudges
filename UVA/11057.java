import java.util.*;
import java.util.stream.*;

class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    while(s.hasNext()) {
      int numBooks = s.nextInt();
      List<Integer> bookPrices = new ArrayList<>();
      for (int i = 0; i < numBooks; i++) {
        bookPrices.add(s.nextInt());
      }
      int target = s.nextInt();
      List<Integer> eligibleBooks = bookPrices.stream().filter(x -> x <= target).collect(Collectors.toList());
      System.out.println(findBooks(eligibleBooks, target));
    }
  }

  private static String findBooks(List<Integer> books, int target) {
    Collections.sort(books);
    int l = 0;
    int r = books.size() - 1;
    int bestDiff = Integer.MAX_VALUE;
    int bestL = -1;
    int bestR = -1;
    while (l < r) {
      int sum = books.get(l) + books.get(r);
      if (sum > target) {
        r--;
        continue;
      }
      if (sum <= target) {
        if (bestDiff >= target - sum) {
          bestDiff = target - sum;
          bestL = l;
          bestR = r;
        }
        l++;
      }
    }
    return "Peter should buy books whose prices are " + books.get(bestL) + " and " + books.get(bestR) + ".\n";
  }
}
