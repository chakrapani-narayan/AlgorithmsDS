package dsp;

public class MySort {
	private static int size = 15;
	private static int[] data = {45, 672, 3, 21, 100, 0, -4, -27, 3, 6, 39, 64, -100, 30, 65};
	private static int[] temp = new int[size];
	
	//// merge sort 
	private static void merge(int left, int mid, int right) {
		
		int i = left;
		int j = mid + 1;
		for(int k = left; k <= right; k++) {
			if(i <= mid && j <= right) {
				if(data[i] < data[j])
					temp[k] = data[i++];
				else
					temp[k] = data[j++];
			} else if (i > mid) {
				temp[k] = data[j++];
			} else {
				temp[k] = data[i++];
			}
		}
		
		for(int k = left; k <= right; k++) {
			data[k] = temp[k];
		}
	}
	
	private static void mergeSort(int left, int right) {
		if(left < right) {
			int mid = left + (right - left ) / 2;
			mergeSort(left, mid);
			mergeSort(mid + 1, right);
			merge(left, mid, right);
		}
	}
	
	public static void mergeSort() {
		mergeSort(0,size -1);
	}
	// merge sort
	
	
	
	//// quick sort
	
	private static int getPivotIndex(int left, int right) {
		int pivot = data[right];
		int wall = left;
		int temp;
		for ( int i = left; i < right ; i++) {
			if(data[i] < pivot) {
				temp = data[wall];
				data[wall] = data[i];
				data[i] = temp;
				wall++;
			}
		}
		temp = data[wall];
		data[wall] = data[right];
		data[right] = temp;
		return wall;
	}
	
	private static void quickSort(int left, int right) {
		if(left < right) {
			int pivotIndex = getPivotIndex(left, right);
			quickSort(left, pivotIndex - 1);
			quickSort(pivotIndex + 1, right);
		}
		
	}
	
	public static void quickSort() {
		quickSort(0, size -1);
	}
	// quick sort
	
	public static void print() {
		for(int i = 0; i < size; i++) {
			System.out.println(" " + data[i]);
		}
	}
}
