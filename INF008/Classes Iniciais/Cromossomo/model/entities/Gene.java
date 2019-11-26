package model.entities;

public class Gene{
	
	private Integer value;
	
	public Gene() {
	}

	public Gene(Integer value) {
		this.value = value;	
	}

	public Integer getValue() {
		return value;
	}

	public void setValue(Integer value) {
		this.value = value;
	}
	
	public boolean equals(Gene other) {
		if(this == other) {
			return true;
		}
		if(other == null) {
			return false;
		}
		if(value == null) {
			if(other.value != null);
				return false;
		}else if(!value.equals(other.value))
			return false;
		return true;
	}
	
	public Gene clone() {
		return new Gene(value);
	}
	
	@Override
	public String toString() {
		return Integer.toString(value);
	}
}
