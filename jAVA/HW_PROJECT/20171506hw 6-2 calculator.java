public class calculator implements AddSub , MulDiv{

  double add(double[] a){

    return a[0]+a[1];

  }

  double subtract(double[] a){

    return a[0]-a[1];

  }

  double multiply(double[] a){

    return a[0]*a[1];

  }

   double divide(double[] a){

    return a[0]/a[1];

  }

}