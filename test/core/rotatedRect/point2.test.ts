import { RotatedRect, Point2, Size } from '../../../index'

describe('[core] RotatedRect', () => {
  describe('constructor', () => {
    it('initializes', () => {
      const rotatedRect = new RotatedRect(
        new Point2(10, 20),
        new Size(30, 40),
        50,
      )

      expect(rotatedRect.angle).toStrictEqual(50)
      expect(rotatedRect.center.x).toStrictEqual(10)
      expect(rotatedRect.center.y).toStrictEqual(20)
      expect(rotatedRect.size.width).toStrictEqual(30)
      expect(rotatedRect.size.height).toStrictEqual(40)
    })
  })
})
